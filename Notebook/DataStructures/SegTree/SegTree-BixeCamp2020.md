# Árvores de Segmento (segtrees)

## Motivação

_Caio é um menino muito cuidadoso com seus carrinhos Rodas Quentes, guardando-os em várias caixinhas que ficam alinhadas em sua estante, uma ao lado da outra. Por ser muito organizado, Caio deixa todas suas $n$ caixinhas numeradas da esquerda para a direita (a primeira é a 1, a segunda a 2, e assim por diante). Em cada caixinha, Caio guarda $a_i$ carrinhos, onde $i$ é o número da $i$-ésima caixinha._

_Vira e meche, Caio compra mais carinhos Rodas Quentes. E sempre os coloca numa mesma caixinha. Ou seja, se ele fez uma compra de $k$ carrinhos, vai escolher uma caixinha $i$ para colocar esses carrinhos._

_Além disso, Caio gosta de brincar com os carrinhos. Mas por ser uma criança muito diversificada, sempre que vai brincar, ele escolhe duas caixinhas, $i$ e $j$, e pega todos os carrinhos nas caixinhas de $i$ até $j$ para brincar. Depois de ter brincado o suficiente, ele retorna os carrinhos para as caixinhas em que estavam antes (não me pergunte como ele memoriza cada caixinha de cada carrinho)._

_Apesar de Caio ter uma ótima memória para saber qual carrinho pertence a qual caixinha, ele gostaria de saber com quantos carrinhos ele brincaria se escolhesse duas determinadas caixinhas $i$ e $j$. Como ele é muito novo e não sabe programar, ele pediu sua ajuda para fazer um programa que ajude ele com isso!_

_Inicialmente, Caio vai te falar quantas caixinhas ele tem e quantos carrinhos ele possui em cada caixinha. Depois, Caio pode informar duas coisas ao seu programa: 1) ele comprou $k$ carrinhos e os depositou na caixinha $i$. 2) ele quer saber quantos carrinhos existem da caixinha $i$ até a caixinha $j$._

## Input

A primeira linha contém um valor $n<10^5$ indicando o número de caixinhas.
A segunda linha contém $n$ valores $a_i$ indicando quantos carinhos estão em cada uma das caixinhas.
A terceira linha contém um valor $q<10^5$ indicando quantas operações Caio fará com seu programa.
As $q$ linhas seguintes contém operações do seguinte tipo:
* O primeiro valor da linha é um inteiro $o$ indicando o tipo da operação (1 ou 2);
* Se $o=1$, então a linha conterá dois valores $k$ e $i$ indicando que Caio colocou $k$ carrinhos na caixa $i$;
* Se $o=2$, então a linha conterá dois valores $i$ e $j$ ($i\leq j$) indicando que Caio quer saber quantos carrinhos existem entre as caixinhas $i$ e $j$ (incluindo elas);

**Obs.:** o número de caixinhas não muda.

## Output

Toda vez que uma operação do tipo dois for realizada, seu programa deve imprimir um valor numa linha indicando o resultado dessa operação.

## Resolvendo o problema ingênuamente

A primeira vista, o problema pode ser bastante fácil e talvez vocês já tenham visto algo do tipo. Entretanto, veremos hoje que esse problema esconde um conceito muito maior por trás: **o de consulta e atualização em segmentos.**

Vejamos então uma resolução imediata do problema:

```cpp
const int N = 112345;
int n;
int arr[N];

void update(int i, int k) { arr[i] += k; }
 
int query(int i, int j) {
    int ans = 0;
    for (; i <= j; i++) ans += arr[i];
    return ans;
}
```

Esses dois métodos realizam as operações pedidas no enunciado. Além disso são bem fáceis de analizarmos, `update` é $O(1)$ e `query` é $O(n)$. Logo, como, no pior caso, podemos fazer $q$ operações de `query`, temos uma solução $O(nq)$.

_Isso passa?_

Depende, mas vemos que $n$ e $q$ podem ser da ordem de $10^5$, logo teríamos um algoritmo que realiza algo na ordem de $10^{10}$ operações. E talvez vocês já tenham visto que um computador moderno realiza algo da ordem de $10^9$ operações por segundo. Hum... parece então que levaríamos 10 segundos no pior caso.

Isso já nos mostra que, mesmo que uma das operações seja praticamente instantânea ($O(1)$), isso não importa, pois a outra operação ainda nos dá um gargalo de quão ruim nosso programa pode ser.

**Além disso,** se nós quiséssemos mudar o problema para o seguinte:
_Na operação 1), Caio ao invés de colocar os $k$ carrinhos em uma única caxinha, digamos que ele compra sempre vários e vários carrinhos e quer colocar exatamente $k$ em cada uma das caixinha de $i$ até $j$ (inclusas)._

Veja que agora as duas operações são $O(n)$! Ou seja, o algoritmo é __sempre__ $O(nq)$.

Será que não podemos diminuir essa complexidade? Veja que estamos assumindo algo muito importante no problema: Caio sempre faz operações considerando caixinhas __adjacentes__. Chamamos isso se __segmentos__ de caixinhas.

Existe uma estrutura de dados chamada __Árvore de Segmentos__ que é o tópico da aula de hoje. Ela nos permite realizar as duas operações (que chamamos de consulta e atualização) em $O(\log n)$, muito melhor do que linear como tínhamos.

## Representando árvores binárias linearmente

Antes de sair estudando as famosas _segs_, precisamos relembrar e aprender alguns conceitos sobre _árvores binárias_.

Vamos relembrar rapidamente algumas nomenclaturas:

* Uma __árvore__ é um grafo acíclico conexo;
* Uma __árvore enraizada__ é uma árvore cujo um vértice é fixado e chamado de raiz;
* Numa árvore enraizada, todo nó $u$ possui __filhos__ e um __pai__. (Exceto a raiz que não tem pai). O pai e o filhos são os nós adjacentes de $u$. O pai é o nó adjacente que possui a menor distância até a raiz, é assim que diferenciamos ele dos demais, que são os filhos;
* Um nó $u$ é um __acendente__ de $v$ se $u$ aparece no caminho da raiz até $v$;
* Um nó $u$ é um __descentente__ de $v$ se $v$ aparece no camiho da raiz até $u$;
* Um nó $u$ é uma __folha__ da árvore se $u$ não possui filhos;
* Uma __árvore binária__ é uma árvore enraizada na qual todo nó pode ter no máximo dois filhos;
* Uma árvore binária __cheia__ é uma árvore binária na qual _todos_ os nós possuem dois filhos;
* Uma árvore binária __completa__ é uma árvore binária cheia exceto talvez o último nível;

Relembrados esse conceitos, existe algo muito importante na computação que é a representação de uma árvore binária _completa_ em um array. Provavelmente vocês já sabem como representar grafos e sabem que costumamos representar usando um desses três métodos:
1. Listas de adjacências;
2. Matriz de adjacências;
3. Lista de arestas.

Entretanto, em se tratando de uma árvore binárias completa (que são usadas em estruturas de dados como a árvore binária e o heap (que vocês verão semestre que vem)), podemos representá-las em um array. Dessa forma, temos acesso em $O(1)$ aos nós dessa árvore (talvez precisando apenas fazer algumas continhas).

Para fazer isso, vamos apenas percorrer a árvore nível por nível e ir numerando ela. A raiz se tornará 1, seu filho esquerdo será 2, seu filho direito será 3, o filho esquerdo do esquerdo da raiz será 4 e assim por diante. (para numerar seria basicamente fazer uma BFS, mas não vamos usar isso no algoritmo da segtree)

Fazendo isso, temos algumas propriedades muito interessante para navegar nessa árvore utilizando o array:

1. A raiz é `seg[1]`;
2. Seja $u$ um nó qualquer, se eles possuir filhos, então o filho esquerdo é `seg[2i]` e o direito é `seg[2i+1]`.

Assim, temos uma forma já bastante diferente da que estávamos acostumados a trabalhar em grafos e vocês verão que essa forma nos ajudará bastante.

__Obs.:__ Não estamos usando `seg[0]` para nada. Podemos colocar a raiz no $0$ ao invés de $1$, mas precisaríamos mudar as continhas para achar os filhos de cada nó.

## Finalmente a árvore de segmentos

A árvore de segmentos é uma árvore binária completa em que cada nó representará um segmento do nosso array original com relação a uma operação (ou várias) que nós escolhemos de acordo com o problema.

Esse valor armazenado no nó se refere à operação `query`. Ou seja, se no nosso problema, queremos saber a soma de de $i$ até $j$, então um nó representando esse segmento vai conter essa soma já calculada para nós. 

Para nosso exemplo vamos usar soma, mas a operação poderia ser o mínimo de um segmento, o máximo, a multiplicação, o valor da maior soma contínua possível e por aí vai (as aplicações são MUITAS).

Assim, nossa árvore vai ter a seguinte _semântica_. A raiz conterá a soma de todo o array $[1,n]$. O seu filho esquerdo vai conter a soma da metade esquerda desse intervalo $[1,n/2]$. O seu filho direito vai conter a soma da metade direita desse intervalo $[n/2+1,n]$. E assim funciona para todo nó da árvore, se aquele nó contém a soma do intervalo $[l,r]$, então seu filho esquerdo terá a soma do intervalo $[l,m]$ e o direito do intervalo $[m+1,r]$, onde $m=(l+r)/2$.

Provavelmente você ainda não entendeu como isso vai deixar as coisas mais rápidas, pois parece que criamos um problema ainda maior. Aparentemente essa árvore contém a soma de todos os segmentos possíveis de construir sobre um array de $n$ elementos e então teríamos que achar um jeito de achar esse nó para responder ao Caio. E, aliás, temos um problema maior ainda: o que eu faço quando Caio comprar mais carrinhos? Como atualizamos essa estrutura louca?

_Calma!_

Primeiro, essa árvore não tem _todos_ os segmentos possíveis de existir. Note que nunca consiguiríamos um nó que represente o segmento $[1,7]$. Suponha que a raiz representa $[1,8]$. Então seus filhos representam $[1,4]$ e $[5,8]$. E como sempre vamos quebrando esses segmentos ao meu, nunca vamos conseguir um $[1,7]$. A realidade é que não passam de $n\log n$ nós. Veja que a altura da árvore é sempre proporcional a $\log n$, pois cada nível vai dividindo o intervalo ao meio. Além disso, como cada nó representa um segmento, no "último" nível vamos ter as folhas representando os segmentos $[1,1],[2,2],[3,3]$ e por aí vai. Ou seja, em cada nível temos sempre algo menor ou igual a $n$, resultando nesse estimador superior. (Se tivéssemos todos os segmentos, teríamos algo quadrático).

Mas então ainda restam as dúvidas: como fazer aquelas operações nesse novo tipo de estrutura de dados? E como montar essa estrutura a partir do array original?

### Construindo

Vamos primeiro mostrar como construir esse árvore partindo do nosso array dado pelo Caio.

```cpp
int st[4*N];

void build(int i, int l, int r) {
    if (l == r) { // se estamos numa folha
        st[i] = arr[l]; // então esse nó contém o próprio valor do segmento [l,l]
        // (pois l=r)
    } else {
        int m = (l+r)/2;

        // Construímos recursivamente o filho da direita e esquerda
        build(l, m, 2*i);
        build(m+1,r, 2*i+1);

        // Como o da esquerda possui a soma da metade esquerda do nosso segmento
        // e o da direita possui a soma da metade direita
        //
        // Então o nosso valor é a soma do filho esquerdo com o direito
        st[i] = st[2*i] + st[2*i+1];
    }
}
```

Como estamos falando em árvore, algoritmos recursivos são bastante interativos de pensar. Na construção, nós vamos usar uma recursão com três valores:
1. `i`, indica qual é o nó da árvore que estamos naquele ponto da recursão;
2. `l`, indica a extremidade esquerda do intervalo representado por esse nó;
3. `r`, indica a extremidade direita desse mesmo intervalo.

Resumindo, na chamada `build(i, l, r)` estamos criando o valor do nó $i$ que representa o intervalo $[l, r]$.

Só que vemos que para construir um certo nó $i$ que não seja uma folha, precisamos que seus dois filhos já estejam construídos. Então os construímos recursivamente.

Dessa forma, para construir a árvore toda, basta chamar para a raiz: `build(1, 1, n)`

Como já vimos, temos um máximo de $n\log n$ nós e, portanto, a construção será $O(n\log n)$.

## Atualizando

Vamos agora responder à pergunta de como fazer a operação de atualização. A atualização também é bastante simples. Se queremos atualizar um valor $i$ do array original, então precisamos nos perguntar quais são os nós que representam intervalos que contêm $i$ e atualizar todos esses segmentos. 

Imediatamente, temos que a raiz contém esse $i$, pois ela é a soma de todo o array. Agora, como os filhos da raiz dividem esse intervalo em dois, sabemos que $i$ com certeza está em exatamente um desses dois intervalos. Para achar esse intervalo, basta saber se $i$ é menor ou igual que $m$ ou maior. Se for menor ou igual, então o intervalo da esquerda contém $i$, caso contrário, será o intervalo da direita que o contém.

E vamos repetindo isso até encontrar a folha que representa o intervalo $[i,i]$.

```cpp
void update(int i, int l, int r, int pos, int k) {
    if (l == r) { // Se chegamos na folha, então pos = l = r
        st[l] += k; // Ao chegarmos na raiz, somamos k diretamente
    } else {
        int m = (l+r)/2;

        // Se a posição que queremos atualizar está para a esquerda,
        if (pos <= m) update(2*i, l, m, pos, k); // atualizamos a esquerda.
        // Se a posição que queremos atualizar está para a direita,
        else update(2*i+1, m+1, r, pos, k); // atualizamos a direita.

        // Após atualizar um dos filhos, atualizamos o nó atual
        st[i] = st[2*i] + st[2*i+1];
    }
}
```

Vemos que, se o problema mudasse para "_Caio vende $k$ carrinhos_" ou qualquer outra operação, poderíamos simplesmente trocar o `+= k` por `-= k`.

Além disso, podemos observar que esse método é chamado para todos os nós no caminho da raiz até a folha que representa $[i,i]$, que é no máximo a altura da árvore, que é $O(\log n)$.

Parece que tivemos uma perda, não é verdade? Pois antes tínhamos um algoritmo $O(1)$ para fazer isso e agora temos um algoritmo $O(\log n)$. Mas se lembre da extensão do problema que propus no começo.

Por enquanto, veja que estamos fazendo um update apenas em um ponto do array. Se quisermos mudar o update para que possamos fazer update em um segmento $[i, j]$, podemos usar essa mesma estrutura de dados para fazer isso também em $O(\log n)$, algo que não conseguíamos fazer somente com o array.

## Consulta

Para fazermos a segunda operação, precisamos agora entender como utilizar essa estrutura pré-processada para realizar isso de forma rápida.

Primeiro, como já discutimos, a árvore não possui todos os segmentos possíveis. Logo, o que precisaremos fazer é somar segmentos para conseguir o segmento que desejamos.

Por exemplo, se quisermos a soma de $[1,7]$, então vamos pegar os segmentos $[1,4]$, $[5,6]$ e $[7,7]$. Somando os três nós que representam esses segmentos, teremos a soma do segmento representado por $[1,7]$.

Dessa forma, apresentemos o algoritmo para depois o discutir:

```cpp
int query(int i, int l, int r, int ql, int qr) {
    // Se o segmento da consulta [ql, qr] não intersecta o segmento atual [l, r]
    if (qr < l || r < ql) return 0; // Retornamos uma soma nula

    // Se o segmento atual está completamente contido no segmento da consulta
    if (ql <= l && r <= qr) return st[i]; // Retornamos a soma de l a r

    // Caso contrário, então o segmento atual possui apenas parte da soma desejada
    // e devemos quebrar esse nó nos seus dois subintervalos
    int m = (l+r)/2;
    return query(2*i, l, m, ql, qr)+query(2*i+1, m+1, r, ql, qr);
}
```

Vamos entender o que ele está fazendo.
Novamente temos as mesmas semanticas de sempre para `i`, `l` e `r`.
1. `ql` é a esquerda do intervalo da consulta;
2. `qr` é a direita do intervalo da consulta;

Ou seja, se Caio quer quantos carrinhos existem da caixinha $1$ até a $7$, imprimimos 
`query(1, 1, n, 1, 7)`.

O algoritmo separa os casos em três:
1. $[l, r]$ e $[ql, ql]$ não possuem intersecção. Isso significa que, por exemplo, chegamos ao nós representando $[3,4]$ e queremos a soma de $5$ até $7$. Como não precisamos da soma desse intervalo, podemos simplesmente parar por aqui e retornar 0 nessa parte da busca, não indo mais fundo na árvore;
2. $[l,r]$ está dentro de $[ql, qr]$. Seria o caso de estarmos buscando a soma de $1$ até $7$ e chegarmos no intervalo $[1,4]$. Sabemos que não precisamos ir mais a fundo, pois esse intervalo já contém uma parte da soma que desejamos. 
3. O intervalo $[l,r]$ contém $[ql, qr]$ e algo mais. Seria o caso de estar procurando a soma de $1$ a $7$ e estivéssemos na raiz $[1,8]$. Vemos que não podemos retornar o valor da raiz, pois estaríamos incluindo a soma da oitava caxinha. Assim, o que fazemos é retornar a soma da query da esquerda com a query da direita.

Vamos simular rapidamente `query(1, 1, 8, 1, 7)` encaixando cada chamada em um dos três acima:

1. `query(1, 1, 8, 1, 7)` -> caso 3, chamamos para os filhos (primeiro esquerda);
2. `query(2, 1, 4, 1, 7)` -> caso 2, retornando a soma de $[1, 4]$;
3. Fim da recursão esquerda de 1., chamando a direita:
4. `query(3, 5, 8, 1, 7)` -> caso 3, chamamos para os filhos (primeiro esquerda);
5. `query(6, 5, 6, 1, 7)` -> caso 2, retornando a soma de $[5,6]$;
6.  Fim da recursão esquerda de 4., chamando a direita:
7. `query(7, 7, 8, 1, 7)` -> caso 3, chamamos para os filhos (primeiro esquerda);
8. `query(14, 7, 7, 1, 7)` -> caso 2, retornando a soma de $[7, 7]$;
9. Fim da recursão esquerda de 7., chamando a direita:
10. `query(15, 8, 8, 1, 7)` -> caso 1, retornando 0;
11. Final da recursão direita de 7., somando $[7,7]$ com 0 dá a soma de $[7,7]$;
12. Final da recursão direita de 4., somando $[5,6]$ com $[7,7]$ dá a soma de $[5,7]$;
13. Final da recursão direita de 1., somando $[1,4]$ com $[5,7]$ dá a soma de $[1,7]$,

como desejávamos.

Para esse caso em específico, parece que estamos fazendo mais trabalho até do que somar diretamente os $7$ valores como fazíamos antes, mas a realidade é que para árvores muito grande, os casos 1. e 2. são uma otimização realmente grande, fazendo com que esse algoritmo seja também $O(\log n)$ (a prova é um pouco mais difícil).

## Análise

Como já vimos, por mais que a operação `update` tenha se saído prejudicada, no total, prejudicar ela para fazer com que a `query` caia para $O(\log n)$ é um grande avanço, pois agora nosso algoritmo é $O(q\log n)$.

Vimos que a construção da árvore é $O(n\log n)$, então a realidade é que nosso algoritmo fará o problema em $O(q\log n + n\log n)$, pois primero lemos o array e construímos a árvore e depois realizamos as operações.

No nosso caso, como $q$ pode ser tão grande quanto $n$, teríamos um algoritmo $O(n\log n)$. Pode ser que alguns problemas mais simples não precisem de segtrees, seja lá por que o $q$ é muito pequeno ou por algum outro motivo. Mas como não podemos garantir que os problemas vão sempre ser fáceis, dominar segs é muito interessante, pois nos permite realizar operações antes lineares em tempo logarítmico.

## Lazy Propagation


## Operações não comutativas