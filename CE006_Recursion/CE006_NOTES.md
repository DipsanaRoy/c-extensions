# CE006. Logical OR (`||`) vs Bitwise OR (`|`) in Recursion

| Operator | Behavior                | Short-Circuits?        | Evaluates Both? |
|----------|-------------------------|------------------------|-----------------|
| `\|\|`   | Logical OR (true/false) | ✅ Yes (Stops if true) | ❌ No          |
| `\|`     | Bitwise OR (bit-by-bit) | ❌ No                  | ✅ Yes         |

## Example (Logical OR `||`)

```c
if (funcA() || funcB()) {
    // funcB() called only if funcA() returns 0
}
```

## Example (Bitwise OR `|`)

```c
if (funcA() | funcB()) {
    // Both funcA() and funcB() are called
}
```

## Important

- Infinite recursion can happen if **no function returns true** and you don't handle the base case properly! ⚡

---
