# Trial II — *The Critique*

*Warden of the Foundations · Midterm 1 · 15 %*

This trial **requires** you to use an LLM. You will paste the prompt and the reply, then critique what you got. Reading and judging AI output is part of the job now; we are practicing it on purpose.

---

## The prompt

Open Claude (or your LLM of choice) and paste **this exact prompt**:

> *Write a C++ function template that returns the largest element of a `std::vector<T>`. Handle the case where the vector is empty. Briefly explain your design choices.*

Tell us which tool you used and the date:

- **Tool:** (e.g., Claude / ChatGPT / Copilot Chat / …)
- **Date of the conversation:** YYYY-MM-DD

---

## The LLM's reply

Paste the **full reply**, code and prose. Use a fenced code block for the code. Do not edit the reply — we want to see what you actually got.

```cpp
// (paste the LLM's code here)
#include <vector>
#include <optional>

template <typename T>
std::optional<T> maxElement(const std::vector<T>& vec) {
    if (vec.empty()) {
        return std::nullopt;   // No value available
    }

    T largest = vec[0];
    for (const T& val : vec) {
        if (val > largest) {
            largest = val;
        }
    }
    return largest;
}
```

(paste any prose explanation here, verbatim)

Design Choices Explained
Use of std::optional<T>  
Returning an optional makes the “empty vector” case explicit. Instead of throwing or returning a sentinel value, the caller must check whether a value exists.

Pass vector by const reference  
Avoids copying and allows the function to work with any vector of comparable types.

Manual loop instead of std::max_element  
You could use std::max_element, but writing the loop keeps the logic transparent and avoids dereferencing an iterator when the vector is empty.

(If you prefer the STL version, it’s a one‑liner:
auto it = std::max_element(vec.begin(), vec.end()); — but you still need to check vec.empty().)
---

## My critique  *( ≥ 150 words )*

Your critique must read like an engineer reviewing a colleague's pull request — specific, technical, and naming exactly what the LLM did. A vague critique ("looks fine to me, but it could be better") is *not* full credit even if the LLM's code was great.

Address each of these:

- **Compile.** Did you actually try to compile and run the code? On what types? What happened?
- **Empty case.** What does the empty-vector case actually do in this code? Is the LLM's choice reasonable? Is it different from what *you* would have chosen?
- **Requirements on `T`.** What does the code require of `T`? What happens if you instantiate it with a type that doesn't support `<` (e.g., a custom struct)?
- **Const-correctness.** Pass by value or by reference? Return by value or by reference? Would you change either?
- **`std::max_element`?** Did the LLM cheat by using the algorithm header, or did it write the loop? Which would *you* have shipped, and why?
- **One concrete improvement.** Name one specific change you would make before merging this into a real project. Not "make it better" — a concrete code change.

(your critique — at least 150 words)
