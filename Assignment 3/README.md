# Assignment 2- CS2323

`input.txt`: Contains numbers to be inserted into the trees.
`search.txt`: Contains numbers to be searched from trees.
`delete.txt`: Contains numbers to be deleted from the trees

To change the minimum degree of BTree, change the minDegree variable in `disk_simulation.c`

### Execution

Run the code using the following command in the terminal:

```
make
```

Execute the executable using

```
./exec
```

### Clean

To delete the executable, run:

```
make clean
```

Note: Deletion implemented is right biased i.e. in case 3, when borrowing happens it is first checked in right sibling then left sibling.
