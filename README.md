# 🎓 Student Management System (C Language)

![C](https://img.shields.io/badge/Language-C-blue)
![Version](https://img.shields.io/badge/Version-2.1-green)
![Status](https://img.shields.io/badge/Status-Active-success)
![Platform](https://img.shields.io/badge/Platform-CLI-lightgrey)

## 📌 Overview

This project is part of my C programming learning journey, where I continuously improve the same application as I learn new concepts.

Instead of building multiple small projects, I am evolving **one system step-by-step** to understand how real software grows over time and how maintainable code is developed.

**Current Version: V2.1**

---

## 🚀 Features (V2.1)

* ➕ Add student (Name, Roll Number, Marks)
* 📋 Display all students
* 🔍 Search student:
  * By Name
  * By Roll Number
* ✏️ Update student details
* ❌ Delete student records
* 🆔 Unique roll number system (no duplicates allowed)
* 💾 Persistent storage using binary files (`.dat`)
* ⚡ Auto-save after every operation
* 🧩 Refactored into a modular architecture using multiple source and header files

---

## ⭐ Key Highlights

- Built a complete CRUD system in C
- Implemented persistent storage using binary files
- Designed a unique roll-based identification system
- Applied real-world data modeling using structures
- Refactored a working single-file application into a modular architecture
- Preserved functionality while improving maintainability and readability

---

## 🧠 Concepts Used

* Structures (`struct`)
* File Handling (`fopen`, `fread`, `fwrite`)
* Arrays
* Functions
* Loops & Conditionals
* String Handling (`string.h`)
* Data Validation
* Modular Programming
* Header Files
* Include Guards
* Multi-file Compilation
* `extern` Keyword

---

## 🏗️ Project Evolution

This project is being upgraded version by version:

* **V1.0** → Basic system using arrays (names only)
* **V2.0** → Structured student records + file persistence
* **V2.1** → Complete modular refactor while preserving functionality
* **V3.0 (Planned)** → Advanced features & optimization

---

## 📂 Data Storage

* Student data is stored in a binary file:

  ```
  data/student_data.dat
  ```

* The file is automatically created if it does not exist.
* Data persists even after program exit.

---

## 🔄 Future Improvements (V3 Roadmap)

* [ ] Sorting students (Topper / ranking system)
* [ ] Dynamic memory allocation (remove fixed size limit)
* [ ] Improved input handling using `fgets`
* [ ] Partial search (substring matching)
* [ ] Better CLI experience (clean UI/UX)
* [ ] Student statistics dashboard
* [ ] Enhanced validation and error handling

---

## 🛠️ How to Run

### Compile

```bash
gcc src/*.c -Iinclude -o sms
```

### Run

#### Linux / macOS

```bash
./sms
```

#### Windows (PowerShell)

```powershell
.\sms.exe
```

#### Windows (Command Prompt)

```cmd
sms.exe
```

---

## 📁 Project Structure

```text
Student-Management-System/
│
├── src/
│   ├── main.c
│   ├── student.c
│   ├── file_handler.c
│   └── menu.c
│
├── include/
│   ├── student.h
│   ├── file_handler.h
│   └── menu.h
│
├── data/
│   └── student_data.dat
│
├── README.md
└── .gitignore
```

---

## 📈 Version History

* **V1.0** — Array-based student system (names only)
* **V2.0** — Struct-based system with file persistence
* **V2.1** — Complete modular refactor using multiple source and header files

---

## 🎯 Purpose

This project helps me:

* Apply core C programming concepts in a real program
* Understand how software evolves with new knowledge
* Build strong fundamentals in data handling and program design
* Learn how to refactor and maintain existing codebases
* Develop better software engineering practices

---

## 📚 Learning Journey

I am currently learning C step-by-step and improving this project alongside my progress.

Rather than creating many disconnected projects, I aim to grow this application version by version to simulate how real-world software is developed and maintained.

This project will continue evolving with more advanced features in upcoming versions.

---

## 🔄 Changelog

### V1.0 → V2.0

- Migrated from an array-based system to a `struct`-based design
- Added file handling for persistent storage
- Introduced roll number as a unique identifier
- Implemented duplicate roll validation
- Improved update and delete operations
- Added search by roll number

🔗 Full changes: https://github.com/mdifhamajaz/student-management-system-c/compare/v1.0...v2.0

### V2.0 → V2.1

- Refactored the entire application into multiple source and header files
- Added dedicated modules for file handling, menu management, and student operations
- Introduced include guards for safer header inclusion
- Used `extern` to manage shared global state
- Implemented multi-file compilation
- Improved maintainability and readability without changing functionality

🔗 Full changes: https://github.com/mdifhamajaz/student-management-system-c/compare/v2.0...v2.1

---

⭐ If you're also learning C, feel free to explore this project, suggest improvements, or build your own version alongside!

Happy Coding! 🚀