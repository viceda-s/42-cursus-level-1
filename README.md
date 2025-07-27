# Milestone 1 – Completed

Welcome to my repository showcasing my progress in **Milestone 1** at 42 School. Below you’ll find a focused overview of each project, my precise results, and the technical highlights that set my submissions apart.

## 🏅 My Scores

| Project | Final Score | Notable Features |
| :-- | :--: | :-- |
| Born2beroot | 🌟 125/100 | Netdata bonus service, Linux hardening |
| ft_printf | ✅ 100/100 | Custom C printf, variadic functions |
| get_next_line | 🌟 125/100 | Handles multiple FDs, efficient buffers |

## 🔎 Project Details

### 🖥️ Born2beroot – 125/100 🌟

- **Objective:** Secure installation and configuration of a Linux virtual machine (Debian), in full compliance with 42 criteria.
- **Implementation:**
    - Hardened SSH (root login disabled, custom port).
    - Strict password policies and sudo group configuration.
    - Firewall setup (UFW/FirewallD) with only SSH and monitoring open.
    - Automated user and group creation scripts.
- **Bonus:**
    - Set up encrypted LVM partitions, enhancing system reliability and security.
    - Fully set up a **WordPress** instance using **Lighttpd** as the web server (excluding NGINX/Apache2), with **MariaDB** as the database backend and **PHP** for dynamic content.
    - Installed Netdata as a systemd service for real-time server health monitoring.
- **Skills:** Security by default, scripting, Linux admin best practices.


### 🖨️ ft_printf – 100/100 ✅

- **Objective:** Implement a modular, robust version of the C `printf` function.
- **Features:**
    - Support for `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
    - Safe variadic argument handling.
    - Custom helper functions for number and hex conversions.
    - Defensive error handling and clear return values.
- **Reference:** Key logic split across `ft_printf.c`, `ft_printf_numbers.c`, `ft_printf_utils.c`, and `ft_printf.h`.
- **Skills:** Advanced function pointers, memory management, and modular code.


### 📄 get_next_line – 125/100 🌟

- **Objective:** Read input files line-by-line with full compliance to norm and efficiency standards.
- **Features:**
    - Handles multiple file descriptors simultaneously.
    - Robust buffer management for efficient large file reading.
    - Prevents leaks and dangling pointers with thorough error checks and cleanups.
- **Skills:** Dynamic memory allocation, pointer arithmetic, file I/O at low level.


## 🏆 Personal Achievements

- **Exceeded expectations** with bonus implementations (Netdata) and perfect marks.
- Developed advanced Linux system skills, custom C libraries, and modular coding standards.
- Demonstrated ability to polish and harden projects beyond base requirements for reliability and monitoring.


## 📂 Repository Structure

- Each project is in its own subdirectory with complete source code and, where needed, install/test instructions.


## 🚀 How to Explore

1. Clone this repo:
`git clone https://github.com/YOUR_USERNAME/milestone1-42.git`
2. Check each project folder’s README for build/run details and bonus explanations.

**Contact me on GitHub or by email for collaboration, code review, or project discussions!**

<div style="text-align: center">⁂</div>
