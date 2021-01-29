public class Rational2 {

    private int numerator;
    private int denominator;

    public Rational2(int numerator, int denominator) throws RationalException {
        if (denominator == 0)
            throw new RationalException("Denominator can not be Zero");

        this.numerator = numerator;
        this.denominator = denominator;

        normalize();

    }

    public Rational2(int numerator) {
        this(numerator, 1);
    }

    public Rational2() {
        this(0,1);
    }

    Rational2(Rational2 rational2) {
        this.numerator = rational2.numerator;
        this.denominator = rational2.denominator;
    }

    public Rational2 negate(){

        return new Rational2(-1*this.numerator, this.denominator);
    }

    //public void negate(){}

    public Rational2 inverse(){
        return new Rational2(this.denominator, this.numerator);
    }


    public Rational2 add(Rational2 rational2){

        int newNumtr = (this.numerator * rational2.denominator) + (rational2.numerator * this.denominator);
        int newDomtr = this.denominator * rational2.denominator;

        return new Rational2(newNumtr, newDomtr);
    }

    public void addInPlace(Rational2 rational2){
        int commonDenom = this.denominator * rational2.getDenominator();
        int newNum1 = this.numerator * rational2.getDenominator();
        int newNum2 = rational2.getNumerator() * this.denominator;

        this.numerator = newNum1 + newNum2;
        this.denominator = commonDenom;
        normalize();
    }

    public Rational2 sub(Rational2 rational2){

        int newDomtr = this.denominator * rational2.denominator;
        int newNumtr = (this.numerator * rational2.denominator) - (rational2.numerator * this.denominator);

        return new Rational2(newNumtr, newDomtr);
    }

    public void subInPlace(Rational2 rational2){
        this.addInPlace(rational2.negate());
    }

    public Rational2 mul(Rational2 rational2){
        return new Rational2(this.numerator * rational2.numerator, this.denominator * rational2.denominator);
    }

    public void mulInPlace(Rational2 rational2){
        this.numerator = mul(rational2).numerator;
        this.denominator = mul(rational2).denominator;
    }

    public Rational2 div(Rational2 rational2){
        return new Rational2(mul(rational2.inverse()));
    }

    public void divInPlace(Rational2 rational2){
        this.numerator = div(rational2).numerator;
        this.denominator = div(rational2).denominator;
    }

    public int getNumerator() {
        return numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    public boolean equals(Rational2 rational2){

//        if(this.numerator == rational.numerator && this.denominator == rational.denominator)
//            return true;
//        else
//            return false;
        return this.compareTo(rational2) == 0;
    }


    public int compareTo(Rational2 rational2){

//        double thisVal = (double) numerator / denominator;
//        double rationalVal = (double) rational.numerator/ rational.denominator;
//
//        if(rationalVal < thisVal)
//            return 1;
//
//        else if(rationalVal == thisVal)
//            return 0;
//
//        else
//            return -1;
//

        int lhs = this.numerator * rational2.getDenominator();
        int rhs = this.denominator * rational2.getNumerator();
        return Integer.compare(lhs, rhs);

    }

    private int gcd(int numerator, int denominator){
        if (denominator == 0)
            return numerator;

        else
            return gcd(denominator, numerator%denominator);
    }

    public void normalize(){
        this.numerator = numerator/gcd(this.numerator, this.denominator);
        this.denominator = denominator/gcd(this.numerator, this.denominator);

//        int gcd = gcd(this.num, this.denom);
//        this.num /= gcd;
//        this.denom /= gcd;

        //return new Rational(numerator/gcd(numerator, denominator), denominator/gcd(numerator, denominator));
    }


    @Override
    public String toString() {
        if(denominator == 0 || denominator == 1)
            return Integer.toString(numerator);

        else
        return numerator + "/" + denominator;

    }
}
