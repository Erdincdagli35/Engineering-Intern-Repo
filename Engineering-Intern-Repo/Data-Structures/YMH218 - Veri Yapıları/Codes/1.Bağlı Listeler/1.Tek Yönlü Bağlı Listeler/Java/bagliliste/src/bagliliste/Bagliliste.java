package bagliliste;
/**
 * @author Erdinç
 */
public class Bagliliste {
    public static void main(String[] args) {
        Node n=new Node();
        n.arrayElementRightAdding(1);
        n.arrayElementRightAdding(2);
        n.arrayElementRightAdding(3);
        n.arrayElementRightAdding(11);
        n.arrayElementRightAdding(15);
        n.arrayPrint();
        n.arrayElementLeftAdding(10);
        n.arrayElementLeftAdding(3);
        n.arrayPrint();
        //n.arrayElementMiddleAdding(111, 2); 
        n.arrayElementLeftDelete();
        n.arrayPrint(); 
        //n.arrayElementRightDelete();
        n.sonsil();
        n.arrayPrint();
       
    }
}  
class Node{//Node Classımızı açtık
    int element;//Eleman değişkeni çin elementi tanımladık
    Node tail;//Node Yapıcı(Cons. Metodu) dan faydanarak kuyruk baş ve sonraki durumları için 3 değişkeni tanımladık
    Node head=null;
    Node last=null;
    Node active=null;
    public void arrayPrint(){//Dizimizi yazdırma için arrayprint meth. oluşturduk
        Node temp=head;//Node un temp değişeni(yani atama degişkeni)başa eşitledik her defasında baştaki elemanın dolu olup olmadığına göre hareket edecek çünkü
        while(temp!=null)//temp boş değilse içerdeki işlemi yapacak
        {
            System.out.print(temp.element+" ");//Yani temp elemanını döngü sresince yazdıracak
            temp=temp.tail;//bağlı dizi matığı olduğu için bir sonraki değerin bilgisini tutmak zorunda
                 //aynı zamanda while daki artırma operatörü oalrakta düşünebiliriz
        }System.out.print("\n");
             
    }
    public void arrayElementRightAdding(int arrival)//bir eleman eklemek için gelen bir sayı değerine ihtiyacımız var
    {
        Node x=new Node();//öncelikle yapıcı olarak tanımladığımız node çağırırız
        x.element=arrival;//gelen eleman(kullanıcı tarafından girilen eleman) yapıcıdan çektiğimiz x in elemanına eşit olduppunu gösterdik
        if(head==null)//eğer son elemanın baş kısmı boş ise 
        {
            head=x;//x(girilen elemanı) baş kısmına eşitledik
            x.tail=null;//x in sonrası boş olmalı -->Bağlı liste mantığından geliyor bu teori
            last=x;//aynı zamanda baş eşit olduğu gibi son x eşit olmalıdır
        }
        else{//eger son eleman boş değilse
            x.tail=null;//x in luyruğu her daim boş olmalıdır
            last.tail=x;//sonun kuyruğu x eşit olmalıdır
            last=x;//x son aeşit olmalıdır.
            
        }
    }
    public void arrayElementLeftAdding(int arrival)
    {
        Node x=new Node();//öncelikle yapıcı olarak tanımladığımız node çağırırız
        x.element=arrival;//gelen eleman(kullanıcı tarafından girilen eleman) yapıcıdan çektiğimiz x in elemanına eşit olduppunu gösterdik
        if(head==null)//eğer ilk elemanın baş kısmı boş ise 
        {
            head=x;//yeni data başa eşit olmalı
        }
        else{//eger ilk eleman boş değilse
            x.tail=head;//yeni datanın kuyruğu ilk datamıza eşit olmalı 
            head=x;//baş datası yeniye eşit olmalı
            
        }
    }
    public void arrayElementMiddleAdding(int arrival,int active)
    {
        Node fresh =new Node();Node act =new Node();
        fresh.element=arrival;
        act.element=active;
        if (head==null) {
            fresh.tail=null;
            head=fresh;
        }
        while(fresh.element!=arrival) {
               act=act.tail; 
               
            }
        fresh.tail=act.tail;
        act.tail=fresh;
        act=fresh;
        
    }
    public void arrayElementLeftDelete()
    {
        int temp;
        temp=head.element;
        head=head.tail;
        System.out.println("\nBaşatan Silindi \n");
    }
public void sonsil(){
     Node temp=head;
     while(temp.last!=tail){
         temp=temp.last;
     }
     tail=temp;
     temp=temp.last;
     tail.last=null;
     System.out.println("Sondan silinen="+temp.element);
 }


   
    
}
    
    
                


