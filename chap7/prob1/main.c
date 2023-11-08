print("Opening and closing the file.")

print("Reading chracters from the file.")

text_file = open("read_it.txt", "r")
text_file.close()

	print(text_file.read(1))
	print(text_file.read(5))
 
	print("Reading the entire file ant once.")
	whole_thing = text_file.read()
	print(whole_thing)


    print("Reading chracters from the lile.")

	print(text_file.read(1))
	print(text_file.read(5))
    
	print("Reading one line at a time.")


