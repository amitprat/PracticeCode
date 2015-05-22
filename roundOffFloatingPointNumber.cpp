/*
Write a function which, given two integers (a numerator and a denominator), print the first N digits of a rational number. For example, for 5 / 3 with N=5, the result should be "1.66666". N=2: 1.66


Approach:
Construct each digit of the result one at a time, most to least significant. You'll find long division does exactly this - dividing numerator into denominator and multiplying the denominator by 10 every time. Simply repeat this for however many decimal places you want.
*/

public void print(int num, int denom, int numDigits) {
    StringBuffer sb = new StringBuffer();

    // Compute number to left of decimal
    sb.append(num / denom);
    sb.append('.');
    num = (num % denom) * 10;

    // Compute each digit to the right of the decimal
    while (numDigits > 0) {
        sb.append(num / denom);
        num = (num % denom) * 10;
        numDigits--;
    }
    System.out.println(sb.toString());
}
