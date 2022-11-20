import os,sys

# python test_flex  +  number of test_case you want to check
while True:
    test_case = int(input("please input the # of test_case: "))
    FILE_NAME = "test_1_s"
    if test_case < 10 : 
        FILE_NAME = FILE_NAME + '0' +  str(test_case)
    elif test_case <=16:
        FILE_NAME = FILE_NAME + str(test_case)
    else:
        print("Invalid test_case: " + test_case)
        sys.exit(1)
    command = "../bin/splc ../test/" + FILE_NAME + ".spl"
    os.system(command)