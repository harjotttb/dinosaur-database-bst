# Dinosaur Database (BST)

A dinosaur record database backed by a binary search tree I built from scratch — insert, search, remove, and traverse thousands of dinosaur records, plus visualize the tree structure.

## What it does

- Custom BST (`MyBST`) with full node management — insert, remove (handles 0/1/2-child cases and successor swapping), find, and existence checks
- Dinosaur records loaded from CSV data, each holding fields like name, diet, period, habitat, length, and taxonomy
- All four traversal orders implemented: pre-order, in-order, post-order, and level-order (using callbacks so any operation can be run over the tree)
- `shuffle()` — pulls every record out, shuffles it, and reinserts, so the tree doesn't end up lopsided if the input data comes in sorted order
- `computeHeight()` and `getDeepestLeaf()` for inspecting the tree's shape
- Renders the tree to Graphviz `.dot` format so you can actually see the BST structure as an image while debugging

## What I got out of it

- Implementing BST insert/remove properly, including the tricky two-child removal case (in-order successor)
- Writing traversal functions that take callbacks, so the same tree can support totally different operations without rewriting traversal logic
- Templates + custom comparison operators — the BST only needs `<`, `>`, `==` overloaded on `Dinosaur` (by ID) to sort correctly
- Debugging a real data structure visually with Graphviz instead of just print statements

## Run it

```bash
make
./main_dinosaurs
```

## Notes

Built this for CPSC 131 (Data Structures) at CSUF.
