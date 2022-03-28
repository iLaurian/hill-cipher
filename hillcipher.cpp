/// C++ code to implement Hill Cipher
#include<bits/stdc++.h>
using namespace std;
ifstream f ("date.in");
/// Following function generates the
/// key matrix for the key string
void getKeyMatrix(string key, int keyMatrix[][3])
{
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

/// Following function encrypts the message
void encrypt(int cipherMatrix[][1],
             int keyMatrix[][3],
             int messageVector[][1])
{
    int x, i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;

            for (x = 0; x < 3; x++)
            {
                cipherMatrix[i][j] +=
                    keyMatrix[i][x] * messageVector[x][j];
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

/// Function to implement Hill Cipher
void HillCipher(string message, string key)
{
    /// Get key matrix from the key string
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int messageVector[3][1];

    /// Generate vector for the message
    for (int i = 0; i < 3; i++)
        messageVector[i][0] = (message[i]) % 65;

    int cipherMatrix[3][1];

    /// Following function generates
    /// the encrypted vector
    encrypt(cipherMatrix, keyMatrix, messageVector);

    string CipherText;

    /// Generate the encrypted text from
    /// the encrypted vector
    for (int i = 0; i < 3; i++)
        CipherText += cipherMatrix[i][0] + 65;

    /// Finally print the ciphertext
    cout << CipherText;
}

/// Driver function for above code
int main()
{
    char input[101],a[2]="A",aa[3]="AA"; /// Edit the parameter for strings with more char
    /// Get the message to be encrypted
    /// Put your own message here in capitals
    f.get(input, 100);/// Edit the second parameter for strings with more char
    ///In case the number of letters cannot be grouped by 3 we will compensate by adding extra letters at the end of input
    if(strlen(input)%3==1)
        strcat(input,aa);
    else
        if(strlen(input)%3==2)
        strcat(input,a);
    f.get();
    /// Get the key
    /// test key GYBNQKURP
    char ckey[10];
    f.get(ckey,10);
    char cmessage[3];
    string key,message;
    key+=ckey;
    for(int i=0; i<strlen(input); i=i+3)
    {
        message.clear();
        for(int j=0;j<=2;j++)
        {
            message+=input[i+j];
        }
        HillCipher(message, key);

    }

    return 0;
}

