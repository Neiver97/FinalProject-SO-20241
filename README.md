# Buffer-Overflow


## CVE-2021-3156: Root Shell PoC (Proof of Concept)

This repository contains a Proof of Concept (PoC) exploit for CVE-2021-3156, also known as "Baron Samedit." This exploit allows a local user to gain root privileges on a vulnerable version of `sudo` without brute force. This PoC is intended for educational purposes only.

## Description

CVE-2021-3156 is a heap-based buffer overflow vulnerability in `sudo`, a powerful utility that allows users to run commands with superuser privileges. The vulnerability was discovered by the Qualys Research Team and affects multiple versions of `sudo`. An attacker with access to a local user account can exploit this vulnerability to elevate their privileges to root.

## Tested Environment

- **Operating System:** Kali Linux
- **Sudo Version:** 1.8.31

## Credit

All research credit goes to the Qualys Research Team. For more detailed information, check out their blog post [here](https://blog.qualys.com/vulnerabilities-research/2021/01/26/cve-2021-3156-sudo-heap-based-buffer-overflow-root-privilege-escalation).

## Checking for Vulnerability

You can check if your version of `sudo` is vulnerable by running the following command:

```sh
sudoedit -s Y
```
- If it asks for your password, it's most likely vulnerable.
- If it prints usage information, it isn't vulnerable.
To downgrade to the vulnerable version of sudo on Kali Linux for testing purposes, use the following command:

```sh
sudo apt install sudo=1.8.31-1ubuntu1
```

## Usage
Follow these steps to compile and run the exploit:

1. Clone the repository:
```sh
git clone https://github.com/yourusername CVE-2021-3156-PoC.git
cd CVE-2021-3156-PoC
```
2. Compile the exploit:
make
```sh
make
```
3. Run the exploit:
```sh
./exploit
```
## Precautions
**Educational Purposes Only:** This exploit is intended for educational and research purposes only. Misuse of this exploit can lead to unauthorized access to systems and data, which is illegal and unethical. Always ensure you have permission to test any systems you do not own.

**Testing Environment:** Conduct your tests in a controlled environment, such as a virtual machine or isolated network, to avoid any unintended consequences on production systems.

**Update Sudo:** Ensure that sudo is updated to the latest version to mitigate this vulnerability. You can update sudo using your package manager:

## Conclusions
CVE-2021-3156 highlights the critical importance of keeping system software up to date to protect against potential security vulnerabilities. The discovery and responsible disclosure by the Qualys Research Team underscore the value of diligent security research and prompt action to mitigate risks. By understanding and responsibly utilizing PoCs like this one, security professionals can better safeguard their systems and prepare for potential threats. It is essential to test and verify vulnerabilities in a controlled environment and to follow best practices for system security, including regular updates and patches.
