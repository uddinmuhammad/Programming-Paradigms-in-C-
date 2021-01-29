public class Rational
{
    private int numerator;
    private int denominator;

    public Rational(int numerator, int denominator) throws RationalException {
        if (denominator == 0)
            throw new RationalException("Denominator can not be Zero");

        this.numerator = numerator;
        this.denominator = denominator;

        normalize();

    }

    public Rational(int numerator) {
        this(numerator, 1);
    }

    public Rational() {
        this(0,1);
    }

    Rational(Rational rational) {
        this.numerator = rational.numerator;
        this.denominator = rational.denominator;
    }


    public Rational negate(){
        return new Rational(-1*this.numerator, this.denominator);
    }


    public Rational inverse(){
        return new Rational(this.denominator, this.numerator);
    }

    public void addInPlace(Rational r)
    {
        int commonDenom = this.denominator * r.getDenominator();
        int newNum1 = this.numerator * r.getDenominator();
        int newNum2 = r.getNumerator() * this.denominator;

        this.numerator = newNum1 + newNum2;
        this.denominator = commonDenom;
        normalize();
    }

    public Rational add(Rational r)
    {
        Rational newR = new Rational(this);
        newR.addInPlace(r);
        return newR;
    }

    public void subInPlace(Rational r)
    {
        this.addInPlace(r.negate());
    }

    public Rational sub(Rational r)
    {
        Rational newR = new Rational(this);
        newR.subInPlace(r);
        return newR;
    }

    public void mulInPlace(Rational r)
    {
        this.numerator *= r.getNumerator();
        this.denominator *= r.getDenominator();
        normalize();
    }

    public Rational mul(Rational r)
    {
        Rational newR = new Rational(this);
        newR.mulInPlace(r);
        return newR;
    }


    public void divInPlace(Rational r)
    {
        this.mulInPlace(r.inverse());
    }

    public Rational div(Rational r)
    {
        Rational newR = new Rational(this);
        newR.divInPlace(r);
        return newR;
    }

    public int getNumerator() { return this.numerator; }

    public int getDenominator() { return this.denominator; }


    public boolean equals(Rational rational){

        if(this.numerator == rational.numerator && this.denominator == rational.denominator)
            return true;
        else
            return false;
    }


    public int compareTo(Rational rational){

        double thisVal = (double) numerator / denominator;
        double rationalVal = (double) rational.numerator/ rational.denominator;

        if(rationalVal < thisVal)
            return 1;

        else if(rationalVal == thisVal)
            return 0;

        else
            return -1;
    }

    private int gcd(int numerator, int denominator){
        if (denominator == 0)
            return numerator;

        else
            return gcd(denominator, numerator%denominator);
    }

    private void normalize()
    {
        int gcd = gcd(this.numerator, this.denominator);
        this.numerator /= gcd;
        this.denominator /= gcd;
    }

        @Override
    public String toString() {
        if(denominator == 0 || denominator == 1)
            return Integer.toString(numerator);

        else
        return numerator + "/" + denominator;

    }

}


