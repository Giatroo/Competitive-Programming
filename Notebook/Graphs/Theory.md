# Elementary Graph Theory

This is a summary of all the important formulas and concepts of the book [Grafos - Uma introdução](http://www.obmep.org.br/docs/apostila5.pdf).

## First definitions

**Def.:** A **graph** is a orded pair G = (V, E) where V is a set of *vertices* and E is a set of *edges*.
Vertices can be anything (numbers, characters, fields) and edges are sets with two elements of V.

For instance, supose $V = \{6A, 6B, 7A, 7B, 8A, 8B\}$ and $E = \{\{6A, 7A\}, \{6A, 7B\}, \{6A, 8B\}, \{6B, 7A\}, \{6B, 8A\}, \\ \{6B, 8B\}, \{7B, 8A\}, \{7B, 8B\}, \{8A, 8B\}\}$

It's hard to visualize such graph with these sets, so we can draw it:

![](data:image/png;base64,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)