public class Main {

    public static void main(String[] args) {
        Rational2 rational21 = new Rational2(1, 2);
        Rational2 rational2 = new Rational2(1, 2);

        //System.out.println(rational1.add(rational2));
        //rational1.addInPlace(rational2);
        //System.out.println(rational1);

//        System.out.println(rational1.sub(rational2));
//        rational1.subInPlace(rational2);

//        System.out.println(rational1.mul(rational2));
//        rational1.mulInPlace(rational2);

        //System.out.println(rational1.div(rational2));
        //rational1.divInPlace(rational2);

        System.out.println(rational21);

        //System.out.println(rational1.equals(rational2));

       int gcf = gcd(14,49);
        System.out.println(gcf);


        reduceFraction(14, 21);
    }



    public static int gcd(int numerator, int denominator){
        if (denominator == 0)
            return numerator;

        else
            return gcd(denominator, numerator%denominator);
    }


    public static void reduceFraction(int x, int y)
    {
        int d;
        d = gcd(x, y);

        x = x / d;
        y = y / d;

        System.out.println("Num: " +x+ "\nDom: " +y);
    }

}
