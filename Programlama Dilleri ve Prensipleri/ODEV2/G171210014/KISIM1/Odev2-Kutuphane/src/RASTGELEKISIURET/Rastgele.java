/**
*
* @author Aslıhan Çetiner aslihan.cetiner@ogr.sakarya.edu.tr
* @since 26.04.2020
* <p>
* G171210014 1-C 
* </p>
*/
package RASTGELEKISIURET;

/**
 *
 * @author emre
 */
public class Rastgele {
 
    public int Uret()//Rastgele sayı oluşturma fonksiyonu.
{
    int tut = 0 ;//nanotime()dan gelen değeri tutan değişken.
      tut = (int)System.nanoTime();//nanotime()dan aldığım değeri değişkene atadım.
            if (tut<0)//nanotime()dan gelen değerinin eksi olmasını önledim.
	    {
		tut=tut*(-1);
	    }
             tut=tut%10;//0-10 aralığının gelmesini sağladım.
        
    
   return tut;//integer değişkeni returnle döndürdüm.
} 
       public int RUret(int a)// parametreye göre Rastgele sayı oluşturma fonksiyonu.
{
    int tut = 0 ;//nanotime()dan gelen değeri tutan değişken.
      tut = (int)System.nanoTime();//nanotime()dan aldığım değeri değişkene atadım.
            if (tut<0)//nanotime()dan gelen değerinin eksi olmasını önledim.
	    {
		tut=tut*(-1);
	    }
             tut=tut%a;//istenen aralığa göre üretimi sağladım.
        
    
   return tut;//integer değişkeni returnle döndürdüm.
} 
    
   public int YasUret()//0-100 aralığında Rastgele sayı oluşturma fonksiyonu.
{
    int tut = 0 ;//nanotime()dan gelen değeri tutan değişken.
    
	    tut = (int)System.nanoTime();//nanotime()dan aldığım değeri değişkene atadım.
            if (tut<0)//nanotime()dan gelen değerinin eksi olmasını önledim.
	    {
		tut=tut*(-1);
	    }
             tut=tut%100;//0-100 aralığının gelmesini sağladım.    
    
   return tut;//integer değişkeni returnle döndürdüm.
}
   public void bekle()//çalışmayı geciktiren fonksiyon.
  {
      final long interval=3;
      long SayiyiAl=System.nanoTime();
      long son=0;
      do
      {
          son=System.nanoTime();
      }while(SayiyiAl+interval>=son);
  }     
   
}
