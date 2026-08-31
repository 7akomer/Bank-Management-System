#pragma once
#include<iostream>
#include <string>
#include<cmath>
#include <cctype>
#include <fstream>
#include "clsDate.h"
using namespace std;

class clsarray
{
public:

    static   int furandomnumber(int from, int to)
    {
        int random = rand() % (to - from + 1) + from;
        return random;
    }


    static  void voreadarray(int array[100], int& sum)
    {
        cout << "enter a number of arrays: ";
        cin >> sum;
        for (int i = 0;i < sum;i++)
        {
            array[i] = furandomnumber(10, 99);
        }
    }


    static   void voprintarray(int array[100], int sum)
    {
        cout << "contor is : ";
        for (int i = 0;i < sum;i++)
        {
            cout << array[i] << " ";
        }
    }


    static   int fuminimumnumberfromarray(int array[100], int sum)   //İÇäßÔä ÇÚÇÏÉ ÇÕÛÑ ÑŞã
    {
        int tom = array[0];

        for (int i = 0;i < sum;i++)
        {

            if (array[i] < tom)
            {
                tom = array[i];
            }

        }
        return tom;
    }


    static   int fumaxnumberfromarray(int array[100], int sum)  //İÇäßÔä ÇÚÇÏÉ ÇßÈÑ ÑŞã
    {
        int tom = 0;

        for (int i = 0;i < sum;i++)
        {

            if (array[i] > tom)
            {
                tom = array[i];
            }

        }
        return tom;
    }


    static bool fucheakpalindromearray(int sum, int array[100])   //İÇäßÔä ÇáÊÃßÏ ãä Çä ÇáÇÑŞÇã ŞÇÈáÉ ááŞÑÇÆÉ ãä ÇáÌåÊíä
    {
        for (int i = 0;i < sum;i++)
        {
            if (array[i] != array[sum - 1 - i])
            {
                return 0;
            }
        }
        return 1;
    }


    static int  fuoddnumbefromrarray(int array[100], int sum)     //İÇäßÔä ÇÑÌÇÚ ÇáÇÑŞÇã ÇáÒæÌíÉ
    {
        int contor = 0;
        for (int i = 0;i < sum;i++)
        {
            if (array[i] % 2 == 0)
            {
                contor++;
            }
        }
        return contor;
    }


    static   int  fuevennumbefromrarray(int array[100], int sum)     //İÇäßÔä ÇÑÌÇÚ ÇáÇÑŞÇã ÇáİÑÏíÉ 
    {
        int contor = 0;
        for (int i = 0;i < sum;i++)
        {
            if (array[i] % 2 != 0)
            {
                contor++;
            }
        }
        return contor;
    }


    static   int  fupositivenumberfromarray(int array[100], int sum)   //İÇäßÔä ÇÚÇÏÉ ÚÏÏ ÇáÇÚÏÇÏ ÇáãæÌÈÉ
    {
        int contor = 0;
        for (int i = 0;i < sum;i++)
        {
            if (array[i] >= 0)
            {
                contor++;
            }
        }
        return contor;
    }


    static  int  funegativenumbefromrarray(int array[100], int sum)  //İÇäßÔä ÇÚÇÏÉ ÚÏÏ ÇáÇÚÏÇÏ ÇáÓÇáÈÉ
    {
        int contor = 0;
        for (int i = 0;i < sum;i++)
        {
            if (array[i] <= 0)
            {
                contor++;
            }
        }
        return contor;
    }

};

class clschar : public clsarray
{
public:
   


    static  char furandomcapitalletter()
    {

        return char(furandomnumber(65, 90));
    }

    static   char furandomsmallletter()
    {
        return char(furandomnumber(97, 122));
    }

    static char furandomspecialchar()
    {
        return char(furandomnumber(33, 47));
    }

    static  void voprintfromAAAtoZZZ()
    {
        for (int i = 65; i <= 90;i++)
        {
            for (int contor = i;contor <= 90;contor++)
            {
                for (int f = contor;f <= 90;f++)
                {
                    cout << char(i) << char(contor) << char(f) << endl;
                }

            }

        }

    }

    static string fustringupper(string text)       //İÇäßÔä ÊÍæíá ÇáÌãá ĞÇÊ ÇáÍÑæİ ÇáÕÛíÑÉ Çáì ÍÑæİ ßÈíÑÉ
    {




        for (short i = 0;i < text.length();i++)
        {
            if (text.at(i) != ' ')
            {
                text.at(i) = toupper(text.at(i));
            }
        }
        return text;

    }

    static  string fustringlower(string text)    //İÇäßÔä ÊÍæíá ÍÑæİ ÇáÌãáÉ ãä ßÈíÑÉ Çáì ÕÛíÑÉ
    {


        for (short i = 0;i < text.length();i++)
        {
            if (text.at(i) != ' ')
            {
                text.at(i) = tolower(text.at(i));
            }
        }
        return text;

    }

    static   char fuinvertchar(char x)     //İÇäßÔä ÊÍæíá ÇáÍÑİ ãä ÕÛíÑ Çáì ßÈíÑ æÇáÚßÓ
    {
        return isupper(x) ? tolower(x) : toupper(x);
    }





};

class clsmath : public clschar
{
public:
    static   bool  fuprimenumber(int number)  //İÇäßÔä ÇáÊÃßÏ ãä Çä ÇáÑŞã Çæáí
    {
        int c, m = round(number / 2);
        for (c = 2;c <= m;c++)
        {
            if (number % c == 0)
            {
                return 0;
            }

        }
        return 1;
    }

    static   bool fuperfuctnumber(int number)   // perfuctÇäßÔä ÇáÊÃßÏ ãä Çä ÇáÑŞã Çá
    {
        int i, contor, sum = 0;
        for (i = 2;i <= number;i++)
        {
            if (number % i == 0)
            {
                contor = number / i;
                sum = sum + contor;

            }
        }

        if (sum == number)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    static int  fureversnumber(int numbers)  //İÇäßÔä ŞáÈ ÇáÑŞã ÇáãÏÎá
    {
        int contor = 0, number2 = 0;
        while (numbers > 0)
        {

            contor = numbers % 10;
            numbers = numbers / 10;
            number2 = number2 * 10 + contor;
        }
        return number2;
    }

   

    static  short fugivennumberinmatrix(int array[3][3], short rows, short cols)     //İÇäßÔä ÇáÈÍË Úä ÊßÑÇÑÇÊ ÚÏÏ ãÚíä İí ÇáãÇÊÑíßÓ
    {
        short number;
        cout << "pleas enter a number of cheak : ";
        cin >> number;
        short sum = 0;
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < cols; j++)
            {
                if (array[i][j] == number)
                {
                    sum++;
                }
            }
        }
        cout << "number [" << number << "] count in matrix is : ";
        return sum;

    }


};

class clscompletprogramadvance : public clsmath
{

    

    public:
        enum enCharType {
            SamallLetter = 1, CapitalLetter = 2,
            Digit = 3, MixChars = 4, SpecialCharacter = 5
        };

        static void  Srand()
        {
            //Seeds the random number generator in C++, called only once
            srand((unsigned)time(NULL));
        }

        static  int RandomNumber(int From, int To)
        {
            //Function to generate a random number
            int randNum = rand() % (To - From + 1) + From;
            return randNum;
        }

        static char GetRandomCharacter(enCharType CharType)
        {

            //updated this method to accept mixchars
            if (CharType == MixChars)
            {
                //Capital/Samll/Digits only
                CharType = (enCharType)RandomNumber(1, 3);

            }

            switch (CharType)
            {

            case enCharType::SamallLetter:
            {
                return char(RandomNumber(97, 122));
                break;
            }
            case enCharType::CapitalLetter:
            {
                return char(RandomNumber(65, 90));
                break;
            }
            case enCharType::SpecialCharacter:
            {
                return char(RandomNumber(33, 47));
                break;
            }
            case enCharType::Digit:
            {
                return char(RandomNumber(48, 57));
                break;
            }
        defualt:
            {
                return char(RandomNumber(65, 90));
                break;
            }
            }
        }

        static  string GenerateWord(enCharType CharType, short Length)

        {
            string Word;

            for (int i = 1; i <= Length; i++)

            {

                Word = Word + GetRandomCharacter(CharType);

            }
            return Word;
        }

        static string  GenerateKey(enCharType CharType = CapitalLetter)
        {

            string Key = "";


            Key = GenerateWord(CharType, 4) + "-";
            Key = Key + GenerateWord(CharType, 4) + "-";
            Key = Key + GenerateWord(CharType, 4) + "-";
            Key = Key + GenerateWord(CharType, 4);


            return Key;
        }

        static void GenerateKeys(short NumberOfKeys, enCharType CharType)
        {

            for (int i = 1; i <= NumberOfKeys; i++)

            {
                cout << "Key [" << i << "] : ";
                cout << GenerateKey(CharType) << endl;
            }

        }

        static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
        {
            for (int i = 0; i < arrLength; i++)
                arr[i] = RandomNumber(From, To);
        }

        static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
        {
            for (int i = 0; i < arrLength; i++)
                arr[i] = GenerateWord(CharType, Wordlength);

        }

        static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
        {
            for (int i = 0; i < arrLength; i++)
                arr[i] = GenerateKey(CharType);
        }

        static  void Swap(int& A, int& B)
        {
            int Temp;

            Temp = A;
            A = B;
            B = Temp;
        }

        static  void Swap(double& A, double& B)
        {
            double Temp;

            Temp = A;
            A = B;
            B = Temp;
        }

        static  void Swap(bool& A, bool& B)
        {
            bool Temp;

            Temp = A;
            A = B;
            B = Temp;
        }

        static  void Swap(char& A, char& B)
        {
            char Temp;

            Temp = A;
            A = B;
            B = Temp;
        }

        static  void Swap(string & A, string & B)
        {
            string Temp;

            Temp = A;
            A = B;
            B = Temp;
        }

        static  void Swap(clsDate & A, clsDate & B)
        {
            clsDate::SwapDates(A, B);

        }

        static  void ShuffleArray(int arr[100], int arrLength)
        {

            for (int i = 0; i < arrLength; i++)
            {
                Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
            }

        }

        static  void ShuffleArray(string arr[100], int arrLength)
        {

            for (int i = 0; i < arrLength; i++)
            {
                Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
            }

        }

        static string  Tabs(short NumberOfTabs)
        {
            string t = "";

            for (int i = 1; i < NumberOfTabs; i++)
            {
                t = t + "\t";
                cout << t;
            }
            return t;

        }

        static string  EncryptText(string Text, short EncryptionKey)
        {

            for (int i = 0; i <= Text.length(); i++)
            {

                Text[i] = char((int)Text[i] + EncryptionKey);

            }

            return Text;

        }

        static string  DecryptText(string Text, short EncryptionKey)
        {

            for (int i = 0; i <= Text.length(); i++)
            {

                Text[i] = char((int)Text[i] - EncryptionKey);

            }
            return Text;

        }

    


};


class clsUtil : public clscompletprogramadvance
{
   
public:
    
    //ÍÏíËÉ ÇáÒíÇÏÉ


    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }



    

};

