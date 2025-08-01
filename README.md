# 🧮 Simple Calculator Using OOP (Modular Version)

A **modular, console-based calculator** built in **C++**, designed to demonstrate clean **Object-Oriented Programming (OOP)** architecture using **Encapsulation**, **Abstraction**, and **Separation of Concerns**.

---

## 📌 Project Goals

This project was created to **practice and apply OOP principles**, and to learn how to organize C++ projects into reusable components using header and source files.

- ✅ Encapsulation
- ✅ Abstraction
- ✅ Separation between UI & Logic
- ✅ Header/source file organization

---

## 🧠 OOP Concepts Applied

### 🔐 Encapsulation

- The internal data and states of the calculator are hidden:
  - Attributes like `_Result`, `_PreviousResultsHistory`, and `_TheLastOperation` are **private**.
  - Interaction happens through public methods only (`add`, `subtract`, `clear`, etc.).

- Getters like `result()` and `theLastOperation()` expose data safely, eliminating the need for `friend class`.

---

### 🧠 Abstraction

- The user doesn't see or care **how** operations are applied.
- The internal details like input validation, operation tracking, and error handling are **hidden** inside the logic class.

---

### 🧩 Separation of Concerns

- `CalculatorUI` handles:
  - All user interaction (input/output)
  - Menu display
  - Reading user choices and values

- `Calculator` handles:
  - Operation logic and state management

This keeps both classes **focused**, **testable**, and **easy to maintain**.

---

## ⚙️ Features

- ➕ Add numbers  
- ➖ Subtract numbers  
- ✖️ Multiply numbers  
- ➗ Divide numbers (with zero-division protection)  
- 🔁 Cancel the last operation (undo)  
- 🧹 Clear the current result  
- 📤 Display the current result  
- 🚫 Input validation for menu and values  

---

## 📦 How to Run

1. Compile all files using a C++ compiler:
```bash
g++ main.cpp calculator_logic.cpp calculator_UI.cpp -o calculator
