# 🧮 Simple Calculator Using OOP

A **console-based calculator** built in **C++**, designed to demonstrate core **Object-Oriented Programming (OOP)** concepts like **Encapsulation** and **Abstraction**.

---

## 📌 Project Goals

This project was created as a **practice tool** to apply and understand the principles of:
- 🔐 **Encapsulation**: bundling data and operations inside a class.
- 🧠 **Abstraction**: hiding implementation details and exposing only essential functionality.

---

## 🧠 OOP Concepts Applied

### 🔐 Encapsulation

All the calculator logic is encapsulated inside a single class `Calculator`. Here's how it's implemented:

- **Private Attributes & Methods**:  
  - Internal states like `_Result`, `_PreviousResultsHistory`, and `_TheLastOperation` are **private**.
  - Helper methods like `_DisplayOperatinsMenu()`, `_ReadNumber()`, `_ExecuteOperation()` are **hidden from the user**, ensuring control over how the data is accessed or changed.

- **Public Interface**:  
  - Only essential methods such as `add()`, `subtract()`, `run()`, etc., are exposed for external interaction.
  - This separation keeps the class **robust, secure, and maintainable**.

---

### 🧠 Abstraction

Users of the `Calculator` class:
- Do **not need to know** how each operation works internally.
- Simply interact with `calc.run()` to launch the calculator.

The implementation hides:
- How inputs are validated.
- How previous results are stored.
- How operations are applied internally.

This ensures the user sees only the **necessary interface**, not the internal complexity.

---

## ⚙️ Features

- ➕ Add numbers  
- ➖ Subtract numbers  
- ✖️ Multiply numbers  
- ➗ Divide numbers (with zero-division error handling)  
- 🔁 Cancel the last operation (undo)  
- 🧹 Clear the current result  
- 📜 Operation history support  
- 🚫 Input validation for numbers and menu choices  

---

## 💡 Example Output

