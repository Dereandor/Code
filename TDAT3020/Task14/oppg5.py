message = 'YÆVFBVBVFRÅVBV'
ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ'

for shift in range(len(ALPHABET)):
    DEC_message = ''
    for i in range(len(message)):
        for j in range(len(ALPHABET)):
            #print("{}   {}".format(ENC_message[i],ALPHABET[j]))
            if message[i] == ALPHABET[j]:
                #print("match!")
                DEC_message += ALPHABET[(j+shift)%29]
                break
    print("Shift: {}  msg: {}".format(shift,DEC_message))

    #Shift 12 git HJERNEN ER ALENE, den eneste som gir noe mening