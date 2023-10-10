# This python program is for writing data into GPA Calculator and Assignment Reminder

gpacal = open("insert-your-grades-and-corresponding-unit-here.txt", mode = 'a')
asmrdr = open("reminder.txt", mode = 'a')

stop = False
print("This python program is an entension of the study helper, for facilitating the data input process.")

while (stop == False):
    choice = input("[1]: Input data for GPA Calculator\n[2]: Input data for Assignment Reminder\nPlease enter your choice: ")
    if choice == '1':
        scode = input("Please enter your subject code: ")
        if len(scode) != 8:
            print("Invalid input. Please input again.")
            continue
        gpacal.write("\n")
        gpacal.write(scode)
        gpacal.write(" ")
        grade = input("Please input your grade for the subject: ")
        gpacal.write(grade)
        gpacal.write(" ")
        unit = input("Please input corresponding unit for the subject: ")
        gpacal.write(unit)
    elif choice == '2':
        scode = input("Please enter your subject code: ")
        if len(scode) != 8:
            print("Invalid input. Please input again.")
            continue
        asmrdr.write("\n")
        asmrdr.write(scode)
        asmrdr.write(" ")
        num = input("Please input the assignment number: ")
        asmrdr.write(num)
        asmrdr.write(" ")
        day = input("Please input the day of the due date for the assignment (DD): ")
        asmrdr.write(day)
        asmrdr.write(" ")
        month = input("Please input the month of the due date for the assignment (MM): ")
        asmrdr.write(month)             
    else:
        print("Your input is invalid, please enter again.\n")
        
    cte = input("Do you wish to continue entering more data? [Y/N] ")
    if cte == 'N':
        print("Thank you for using the program.\nPlease use the C program for GPA calculation and Assignment Reminder.")
        stop = True

gpacal.close()
asmrdr.close()