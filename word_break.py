'''
______________Asumptions__________________

1. Function returns false if subset of woard is not in DIctonary
2. Words are seprated by blank space
3. Funcrion returns false if dictonary is empty
4. Function retuens False is words are not in Dictonary  
5. Function returns false if input string is empty

'''




def word_break(dictonary,sentence,demiliter):
	splitedWord=""
	word=""
	spacecount=0
	for letter in sentence:
		word=word+letter
		if(word in dictonary):
			spacecount+=1
			splitedWord=splitedWord+" "+word
			word=""
	if (len(splitedWord) != (len(sentence)+spacecount)) or sentence=="":
		return False
	return splitedWord


if __name__=="__main__":

	#___________Test Cases___________
	
	print("Case 1: Dictonary is empty")
	dictonary={}
	result=word_break(dictonary,"youleavefootprints"," ")
	print(result)


	print("Case 2: Input String is empty")
	dictonary={"pear","salmon","foot","prints","footprints","leave","you","sun", "girl", "enjoy"}
	result=word_break(dictonary,""," ")
	print(result)

	print("Case 3: Input subset of woard is not in DIctonary")
	result=word_break(dictonary,"salmonenjoyapples"," ")
	print(result)

	print("Case 4: Input String is valid")
	result=word_break(dictonary,"youleavefootprints"," ")
	print(result)
    


	
