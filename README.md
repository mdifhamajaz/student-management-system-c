# 🎓 Student Management System (C Language)
![C](https://img.shields.io/badge/Language-C-blue)
![Version](https://img.shields.io/badge/Version-2.0-green)
![Status](https://img.shields.io/badge/Status-Active-success)
![Platform](https://img.shields.io/badge/Platform-CLI-lightgrey)


## 📌 Overview

This project is part of my C programming learning journey, where I continuously improve the same application as I learn new concepts.

Instead of building multiple small projects, I am evolving **one system step-by-step** to understand how real software grows over time.

**Current Version: V2.0**

---

## 🚀 Features (V2)

* ➕ Add student (Name, Roll Number, Marks)
* 📋 Display all students
* 🔍 Search student:

  * By Name
  * By Roll Number
* ✏️ Update student details
* ❌ Delete student
* 🆔 Unique roll number system (no duplicates allowed)
* 💾 Persistent storage using file handling (`.dat`)
* ⚡ Auto-save after every operation

---

## ⭐ Key Highlights

- Built a complete CRUD system in C
- Implemented persistent storage using binary files
- Designed unique roll-based identification system
- Applied real-world data modeling using structures

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

---

## 🏗️ Project Evolution

This project is being upgraded version by version:

* **V1.0** → Basic system using arrays (names only)
* **V2.0** → Structured student records + file persistence
* **V3.0 (Planned)** → Advanced features & optimization

---

## 📂 Data Storage

* Student data is stored in a binary file:

  ```
  student_data.dat
  ```
* The file is automatically created if it does not exist
* Data persists even after program exit

---

## 🔄 Future Improvements (V3 Roadmap)

* [ ] Sorting students (Topper / ranking system)
* [ ] Dynamic memory allocation (remove fixed size limit)
* [ ] Improved input handling using `fgets`
* [ ] Partial search (substring matching)
* [ ] Better CLI experience (clean UI/UX)
* [ ] Code modularization into multiple files

---

## 🛠️ How to Run

### Compile

```bash
gcc main.c -o sms
```

### Run

```bash
./sms
```

*(Windows users can run `sms.exe`)*

---

## 📁 Project Structure

```
Student-Management-System-C
│
├── main.c
├── README.md
└── .gitignore
```

---

## 📈 Version History

* **V1.0** — Array-based student system (names only)
* **V2.0** — Struct-based system with file persistence

---

## 🎯 Purpose

This project helps me:

* Apply core C programming concepts in a real program
* Understand how software evolves with new knowledge
* Build strong fundamentals in data handling and program design

---

## 📚 Learning Journey

I am currently learning C step-by-step and improving this project alongside my progress.

This project will continue evolving with more advanced features in upcoming versions.

---

⭐ If you're also learning C, feel free to explore or build your own version alongside!
---

## 🔄 Changelog

### V1.0 → V2.0
- Migrated from array-based system to `struct`-based design
- Added file handling for persistent storage
- Introduced roll number as unique identifier
- Implemented duplicate roll validation
- Improved update and delete operations
- Added search by roll number

🔗 Full changes: https://github.com/mdifhamajaz/student-management-system-c/compare/v1.0...v2.0