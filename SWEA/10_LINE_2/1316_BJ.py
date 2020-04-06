input_words = []
total_group_number = 0

iter_number = int(input())

for i in range(0, iter_number):
    input_words.append(input())

for word in input_words:
    is_group = True
    checked_char =[]
   
    for i in range(0, len(word)):
        try:
            curr_char = word[i]
            next_char = word[i+1]
   
            if curr_char != next_char:
                if word[i+1] in checked_char:
                    is_group = False
                    break
                else:
                    checked_char.append(curr_char)
            else:
                if word[i] not in checked_char:
                    checked_char.append(curr_char)
        except IndexError:
            continue
    if is_group is True:
        total_group_number += 1

print(total_group_number)