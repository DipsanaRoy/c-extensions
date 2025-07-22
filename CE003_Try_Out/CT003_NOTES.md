# CT003. What is `*token - '0'`?

- `*token` → means the **current character** in the string (for example `'5'`, `'8'`, etc.).
- `'0'` → is the **character** `'0'`, whose **ASCII code** is **48**.

When you do `*token - '0'`, you **convert a character digit into its numeric value**.

---

## Example

Suppose:

| Character | ASCII Value |
|:----------|:------------|
|   `'0'`   |      48     |
|   `'1'`   |      49     |
|   `'2'`   |      50     |
|   `'3'`   |      51     |
|   `'4'`   |      52     |
|   `'5'`   |      53     |
|   `'6'`   |      54     |
|   `'7'`   |      55     |
|   `'8'`   |      56     |
|   `'9'`   |      57     |

If `*token = '5'`, then:

```text
*token - '0'
= '5' - '0'
= 53 - 48
= 5
```

✅ So `'5'` (character) becomes `5` (integer) — **perfect for calculation**!

---

## Why do we need it?

Because when reading from a string, digits are **characters**, not numbers.  
You **have to convert them** if you want to build the final number.

Otherwise, you would be mistakenly adding ASCII codes!

---

### 🌟 Visual

| What you have (char) | What you need (int) | How to get  |
|:---------------------|:--------------------|:------------|
| `'7'` (char)         | `7` (number)        | `'7' - '0'` |

---

## ⚡ Final shortcut memory tip

> **Characters '0' to '9' are in order** in ASCII.  
> Subtracting `'0'` **normalizes** them to real numbers `0` to `9`.

---
