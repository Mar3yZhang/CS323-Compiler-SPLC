import os,sys

# python test_flex  +  number of test_case you want to check
while True:
    test_case = input("please input the # of test_case: ")
    FILE_NAME = "test_1_r"
    if test_case <=9: 
        FILE_NAME = FILE_NAME + "0" + str(test_case)
    elif 9 < test_case <= 12:
        FILE_NAME = FILE_NAME + str(test_case)
    else:
        print("Invalid test_case: " + test_case)
        sys.exit(1)
    command = "../bin/splc.out ../test/" + FILE_NAME + ".spl"
    os.system(command)