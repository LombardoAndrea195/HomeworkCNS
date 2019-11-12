#!/bin/bash

while IFS= read -r password; do
	
	openssl enc -aes-192-cbc -pbkdf2 -d -in ciphertext.enc -out "${password}.txt" -pass pass:${password}
	if file "${password}.txt" | grep 'ASCII text'; then
		echo "Password Match:"${password}
		echo "Find out the key and the plaintext!"
		cat "${password}.txt"
	else
		rm "${password}.txt"
	fi
done < engmix.txt
                              
