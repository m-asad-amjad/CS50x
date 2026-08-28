#Prompt the user for some text
text = input("Text :")

#setting letters, words, sentences to zero
letters = 0
words = 1
sentences = 0

#chcking each character in text
for character in text:

    if character.isalpha(): #counting letters
        letters = letters + 1

    if character == " ": #counting words
        words = words + 1  #there is one space if two words are present
                       #that's why taking words = 1
    #counting sentences
    if character == "." or character == "!" or character == "?":
        sentences = sentences + 1

#calculating value of L according to CS50 website
L = letters / words * 100
#calculating value of S according to CS50 website
S = sentences / words * 100

#Compute the Coleman-Liau index
index = 0.0588*L - 0.296*S - 15.8

#Print the grade level according to cs50 website
if index < 1:
    print ("Before Grade 1")

elif index >= 16:
    print ("Grade 16+")

else:
    print(f"Grade {round(index)}")
