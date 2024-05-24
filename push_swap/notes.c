CVb3d2023

leaks -atExit -- ./push_swap

-g -fsanitize=address

commmand+h with extension in viscose, fn+f1 sinom

Notes for Wednesday:

Basically, go through all the files and functions and see which ones don’t have securities. Be careful about the type of return value (NULL, “ “, 0, 1) depending on the return type of the function
-2147483648
2147483647
It doesn’t bump the largest up to the top




On macOS, you can sort by memory usage in top by following these steps:
1. Open a terminal. 
2. Run the top command by typing top and pressing Enter. 
3. Press o to bring up the sorting options. 
4. Then type rsize and press Enter. This will sort the processes by resident memory size. 
5. Once you've found your push_swap program in the list, you can see its memory usage in the RSIZE column. 
6. To exit top, press q. 



This line in the library file: # define PL ft_printf("line: %i ; file: %s\n", __LINE__, __FILE__);
Let’s you type “PL;” anywhere in the code and it will print out the file and line of the file, just a more convenient printf.

Int max/min:
-2147483648
2147483647


Fsanitizer -g ? In makefile 

Leaks command in terminal

Exam Notes:

Comlan Giovanni short version short_1 (same as his standard) is the shortest one that passes grademe

Turk or radix 

So turk is constantly looking for the cheapest item to move from a to b. This is after moving two at random (1st two) and then sorting those two in b. Then regular sorting for the last three elements in stack a. Then, now that stack b is sorted but in descending not ascending order, it can start pushing back over to stack a and just checking each time to make sure it doesn’t need to rotate due to the three leftover.

Radix breaks down numbers into binary and performs bitwise operations to sort based on 1’s 10’s 100’s columns etc, and replaces negative with assigned positive values?

Quick sort is conquer and divide

Insertion sort is…


So can do a makefile for all the lift/printf/gnl etc, 1 only, deleting the existing ones. Each subfolder still needs a a library but the main library can just list the 3 other .h’s








Born2beRoot:

Why VM’s? Cheap, don’t need another physical pc, no associated maintenance, can use snapshots to backup data easily, more secure in case of malware intrusion due to partitioning, handy for testing.

Sudo is super-user do, but it’s also substitute -user do or su do, as it can run normal commands as well as superuser commands

Root is the original superuser and has the ability to do anything on a system.

Virtual is a hypervisor, or a VMM virtual machine manager

Debian is more simple, low level, while CentOS is more suited to enterprise purposes and offers more security.

Apt is lower level and won’t remember or automatically do anything, Aptitude will remember which packages were installed because of others and will uninstall unnecessary ones.

SSH = Secure Shell, security protocol regarding data packet sending and receiving.

APP Armour - Linux security system that provides Mandatory Access Control (MAC) security. Allows the system admin to restrict the actions that processes can perform. It is included by default with Debian. 
Run aa-status to check if it is running.

UFW is uncomplicated firewall, monitors network traffic and blocks or allows ports

Root is the default superuser, but using sudo can allow others to execute commands requiring root’s rights without granting full rights to the user.

Crontab  - name comes from chronometry, for scheduling repetitive tasks - where * * * * * means every minute of every hour of every day of every month and every day of the week

The */10 means every 10 minutes (when using crontab). So the slash basically means “every”.  Same as writing 10,20,30,40,50 * * * * command-to-be-executed


grep = global regular expression print

Wall = write to all. Utility that sends a message to the terminals of all currently logged in users.

getent = allows you to query these databases and retrieve information as if it were coming from the corresponding system files, such as /etc/passwd, /etc/group, and others. It provides a unified way to access information from different databases through a consistent interface.

awk = scans a file line by line (gnl), splits each input line into fields (split), compares input lines/fields to a pattern, performs actions on matched lines

Partioning: 
/	Contains the rest of the tree.
/boot	Contains data that is used before the kernel begins executing user-mode programs
/var	Contains variable files
/tmp	Contains temporary files
/home	Contains HOME users

LVM = Logical Volume Manager and are dynamic positions - can be modified without rebooting to inform kernel of changes


Signature in this sense is the unique identifying number for a storage drive/device used by the OS.

In the Linux terminal, the usermod -aG command is used to add an existing user to a secondary group1. Here’s what each option means:
* -a: This stands for ‘append’. This option is used when adding a user to a new group1.
* -G: This option is followed by the group’s name. It specifies the group to which the user is being added1.
So, in your command sudo usermod -aG <groupname> <username>, you’re adding the user (<username>) to the group (<groupname>). If you omit the -a option, the user will be removed from the groups not listed after the -G option1. Always use the -a (append) option when adding a user to a new group1. If the user or group doesn’t exist, the command will warn you1.

The command dpkg -l | grep ssh – is a combination of two commands: dpkg -l and grep ssh, connected by a pipe (|).
Here’s what each part does:
1. dpkg -l: This command lists all packages installed on your system. dpkg is the Debian package management utility, and the -l option tells it to list packages. 
2. |: This is a pipe. It takes the output from the command on its left (in this case, dpkg -l) and uses it as the input to the command on its right. 
3. grep ssh: This command searches the input it receives for lines containing the string “ssh”. grep is a utility for searching text. 
So, put together, dpkg -l | grep ssh – lists all installed packages and then searches that list for packages related to “ssh”. The output will be all lines from the package list that contain the string “ssh”. This is a handy way to check if a certain package, or set of packages, is installed on your system.

The term systemctl doesn’t stand for anything in particular. It’s the name of a command-line utility in Linux. The name is derived from the words ‘system’ and ‘control’, reflecting its purpose as a tool for managing and controlling system services in Linux distributions that use the systemd init system. The systemd system and service manager is responsible for controlling how services are started, stopped, and otherwise managed on the system. The systemctl command provides a way to interact with systemd and control these services. So, in a way, you could think of systemctl as standing for “system control”.

GID = Group Identifier

In the context of configuring sudo in Linux, TTY stands for teletypewriter. It’s a term that comes from a long history before the computer era. Nowadays, the tty command is used to provide the file name of the terminal connected to the standard input1.
When you see requiretty in the sudo configuration file (usually located at /etc/sudoers), it means that sudo will only run when the user is logged in to a real tty, i.e., a terminal session2. This prevents sudo from being used from daemons or other detached processes like cron jobs or web server plugins3. It also means you can’t run it directly from an ssh call without setting up a terminal session3.
The error message sudo: sorry, you must have a tty to run sudo will occur when the sudo command is trying to execute a command that requires a tty1. It is most likely happening because you are running on a Linux distribution with sudo configured by default to require a tty1.
Requiring sudo commands to run from a real tty was generally done as a matter of security concern. However, in reality, this does not provide any real security benefit1. Some Linux distributions have been known to have this as a default configuration1.

1. minlen=10: This sets the minimum length of the password to 10 characters. The user will not be able to set a password that is shorter than this. 
2. ucredit=-1: This requires at least one uppercase letter in the password. The -1 means that at least one character must fulfill the condition (in this case, being an uppercase letter).  f we put a + sign it will refer to maximum characters. 
3. dcredit=-1: This requires at least one digit in the password. 
4. lcredit=-1: This requires at least one lowercase letter in the password. 
5. maxrepeat=3: This sets the maximum number of repeated characters in the password to 3. The user will not be able to set a password with a character that repeats more than this number of times consecutively. 
6. reject_username: This ensures that the password does not contain the username. 
7. difok=7: This sets the number of characters in the new password that must not be present in the old password. In this case, at least 7 characters in the new password must be different from the old password. 
8. enforce_for_root: This enforces the password policy for the root user as well. By default, the root user is exempt from password policies.

who = displays info about currently logged-in users.
lsblk = shows us info about block devices, e.g. storage

Sure, I’d be happy to break down the command for you. Here’s what each part does:
* lsblk: This is a command that lists information about all available or the specified block devices. Block devices are storage devices such as hard drives or flash drives. 
* |: This is a pipe. It takes the output of the command on its left and uses it as the input for the command on its right. 
* grep "lvm": This command searches the input it receives for lines that contain the string “lvm”. In this context, it’s looking for block devices that are part of a Logical Volume Manager (LVM) setup. 
* wc -l: This command counts the number of lines in its input. Here, it’s counting the number of block devices that are part of an LVM setup. 
* $(...): This is command substitution. It runs the command inside the parentheses (in this case, lsblk | grep "lvm" | wc -l) and then replaces the $(...) with the output of that command. 
* if [ ... -gt 0 ]: This is an if statement that checks if the number of LVM block devices is greater than 0. 
* then echo yes; else echo no; fi: If the condition in the if statement is true (i.e., there is at least one LVM block device), then it prints “yes”. Otherwise, it prints “no”. 
So, in summary, this command checks if there are any block devices that are part of an LVM setup on your system and prints “yes” if there are and “no” if there aren’t. I hope this helps! Let me know if you have any other questions.

journalctl = journal control - used for viewing logs collected by systems

shasum - used to compute and check SHA Secure Hash Algorithms  checksums., to identify integrity of a file using SHA-1

dpkg -s = display package - -status.   Shows status of an installed package

which = a simplified version of dpkg -s, just a simple query.

Shamus =used to compute and check SHA (Secure Hash Algo) checksums.This allows you to verify the integrity of a file by comparing it’s checksum with a known value.


Sure, here’s a simple guide on how to use the nano text editor in Debian:
Opening and Creating Files
To open an existing file or create a new one, use the following command:
nano filename.txt
Replace filename.txt with your desired file name.
Basic Navigation
* Use the arrow keys to move the cursor around the text.
* To move to the beginning of the file, press Ctrl + Y.
* To move to the end of the file, press Ctrl + V.
Editing Text
* To cut the current line, press Ctrl + K.
* To paste the last cut text, press Ctrl + U.
* To search for text, press Ctrl + W, then type your search query and press Enter.
Saving and Exiting
* To save changes, press Ctrl + O, then press Enter to confirm the file name.
* To exit nano, press Ctrl + X. If you have unsaved changes, it will ask you if you want to save them.
Remember, you can always press Ctrl + G to bring up the help menu in nano.
Please note that you might need appropriate permissions to edit certain files. Use sudo if necessary. Always be careful when editing system files. Enjoy using nano! 😊
  

https://discord.com/channels/894498037941022730/900132587161391134/1180211039581769849



Sure, here’s a line-by-line explanation of your script:
#!/bin/bash
This line is called a shebang. It tells the system that this script should be executed using bash, the Bourne Again SHell.
# ARCH
arch=$(uname -a)
This line sets the variable arch to the output of the command uname -a, which provides detailed information about the system, including the kernel name, hostname, kernel release, kernel version, machine hardware name, processor type, hardware platform, and operating system.
# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)
This line sets the variable cpuf to the number of physical CPUs. It does this by looking at the /proc/cpuinfo file (which contains detailed info about the CPUs), pulling out lines that contain “physical id”, and counting those lines with wc -l.
# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)
This line sets the variable cpuv to the number of processing units available to the system, which could be cores or threads, depending on the system.
# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
These lines set variables related to RAM usage. ram_total is set to the total amount of RAM in megabytes, ram_use is set to the amount of RAM currently in use, and ram_percent is set to the percentage of total RAM that is currently in use.
# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')
These lines set variables related to disk usage. disk_total is set to the total amount of disk space, disk_use is set to the amount of disk space currently in use, and disk_percent is set to the percentage of total disk space that is currently in use.
# CPU LOAD
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)
These lines set variables related to CPU load. cpul is set to the percentage of time the CPU is idle, cpu_op is set to the percentage of time the CPU is not idle (i.e., under load), and cpu_fin is set to cpu_op but formatted to one decimal place.
# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
This line sets the variable lb to the date and time the system was last booted.
# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
This line sets the variable lvmu to “yes” if Logical Volume Management (LVM) is being used, and “no” otherwise.
# TCP CONNEXIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)
This line sets the variable tcpc to the number of established TCP connections.
# USER LOG
ulog=$(users | wc -w)
This line sets the variable ulog to the number of users currently logged into the system.
# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')
These lines set variables related to the network. ip is set to the system’s IP address, and mac is set to the system’s MAC address.
# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
This line sets the variable cmnd to the number of commands run with sudo.
wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"
This final line uses the wall command to send a message to all users logged into the system. The message contains all the system information gathered by the script. The variables (like $arch, $cpuf, etc.) are replaced with their values when the message is displayed.


AND


Absolutely, I’d be happy to explain further!
The last section of the script is indeed a summary of the other commands. It uses the wall command to send a message to all users logged into the system. The message contains all the system information gathered by the script.
Here’s how it works:
wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"
The wall command sends a message to all users logged into the system. The message is the string of text enclosed in quotes. Inside this string, you see several variables (like $arch, $cpuf, etc.). These variables were defined earlier in the script, each holding the result of a command or calculation that produces the required information.
When the wall command is run, the shell replaces each variable with its value. So, for example, $arch becomes the system architecture information, $cpuf becomes the number of physical CPUs, and so on. This process of replacing variables with their values is called variable substitution.
The result is a message that includes all the system information gathered by the script, formatted as a string of text. This message is then sent to all logged-in users.
So, in summary, the last section of the script is where all the gathered information is assembled into a message and displayed to the users. The variables act as the link between this section and the rest of the script, carrying the results of the earlier commands into the final message. I hope this helps clarify how the script works! Let me know if you have any other questions. 😊

So what’s left is the script, crontab, and testing. Maybe do key last as then it’s no longer in use

Root Useful Commands:

Checking for GUI:
	ls /usr/bin/*session

Checking UFW status:
	sudo ufw status 
	OR
	sudo service ufw status

Checking SSH status:
	sudo service ssh status

Checking OS:
	uname -v
	OR
	uname --kernel-version

Group info:
	getent group <group you want>

Creating new user:
	sudo adduser <name you want>

Creating new group:
	sudo addgroup <group name>

Adding user to group:
	sudo adduser <username> <group>

Checking Hostname:
	hostname

Modifying Hostname:
	sudo vim /etc/hostname
	(change login name here, save and exit)
	sudo vim /etc/hosts
	(same as above)
	sudo reboot
	(rebooting necessary to affect change)

Checking partitions:
	lsblk

Checking sudo installation:
	which sudo
	OR
	dpkg -s sudo

Adding users to sudo group:
	sudo adduser <username> sudo

Checking above:
	getent group sudo

Checking sudo rules:
	(Navigate to root then /var/log/sudo)
	vim /etc/sudoers.d/sudo_config
	
Show path and evidence of sudo log file:
	(path as above)
	ls
	cat sudo_config
	(Run a sample command like sudo vim hello)
	cat sudo_config

Check UFW installation and status:
	(Navigate back to root)
	dpkg -s ufw
	sudo service ufw status

List active UFW rules:
	sudo ufw status numbered

Create new rule:
	sudo ufw allow <number of port>

Verifying creation:
	sudo ufw status numbered

Deleting it:
	sudo ufw delete <number of rule[not portnumber!]>
	(check again as above)

Check SSH installation, status, and port:
	which ssh
	sudo service ssh status

Using SSH to login:
	(open new terminal window)
	(try with root - shouldn’t work) 
	ssh root@localhost -p 4242
	(now with <newly created user>)
	ssh <the new user>@localhost -p 4242
	(then pw associated)

Modifying runtime of script:
	(from home)
	sudo crontab -u root -e
	(change 10 to 1)
	(IF Nano: Ctrl+o to save, the enter, Ctrl+x)
	
Stop then start script without editing text:
	sudo /etc/init.d/cron stop	
	sudo /etc/init.d/cron start

Signature : cbf707404dffdd4f5c6dabab0e50ca8f97881f03
cbf707404dffdd4f5c6dabab0e50ca8f97881f03







941edb798ce4e1c856c658e4193c14737b2f25d0


So if you have a pointer

Sending the ptr (ptr) needs the receiving parameter to be (*ptr)

You can’t dreference this, it sends the value at that spot.

Sending the address of the pointer (&ptr) needs a receiving parameter to be (**ptr)

So that you can dereference this  









-m to separate by commas, -A to omit . And .. files, -t for ordering by date, -p for the slash

Abc
000
012
013
—
019




42.5
4.2 and counter of 1

Counter of 1 and n of 4
Print 4, reset n to 425

Becomes 42.5 and counter 0
Print 2

Divide by 10, adding 1 to counter each tie, then reset number (not n) by say x10  for every counter
Then n-number will be the one to the right 

Or directly count so number keeping being a multiple of 10 or 100 etc

Or a modolus x counter time 10


Shouldn’t after:
 _
‘



5,000 x 0.145

