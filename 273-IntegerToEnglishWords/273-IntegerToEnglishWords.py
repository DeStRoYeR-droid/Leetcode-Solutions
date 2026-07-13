# Last updated: 13/07/2026, 22:21:52
class Solution:
    def numberToWords(self, num: int) -> str:
        if (num == 0):
            return "Zero"
        ones = [
            "" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , 
            "Seven" , "Eight" , "Nine"
        ]
        teens = [
            "Eleven" , "Twelve" , "Thirteen" , "Fourteen" , "Fifteen" ,
            "Sixteen" , "Seventeen" , "Eighteen" , "Nineteen"
        ]
        tens = [
            "" , "Ten" , "Twenty" , "Thirty" , "Forty" , "Fifty" , "Sixty" ,
            "Seventy" , "Eighty" , "Ninety"
        ]
        higher_order = [
            "" , "Thousand " , "Million " , "Billion " , "Trillion ", 
            "Quadrillion " , "Quintillion " , "Sextillion " , "Septillion "
        ]

        i = 0
        words_list = []
        while (num > 0):
            result = ""
            n = num % 1000
            if (n >= 100):
                result += ones[n // 100] + " Hundred "
            n = n % 100
            if (n> 10 and n< 20):
                result += teens[n%100 - 11]
            elif (tens[n // 10]):
                result += tens[n // 10]
                result += " "
                n = n % 10
                result += ones[n]
            elif (n < 10):
                result += ones[n]

            words_list.append(result)
            num = num // 1000
        
        res = ""
        for word in words_list:
            if (word):
                res = word.rstrip() + " " + higher_order[i] + res
            i += 1
        res = res.rstrip()
        return res