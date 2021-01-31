
package baglilisteıslemleri;
/**
 *
 * @author Erdinç Dağlı
 */
class Node{
    public int data;
    public Node next;
    public Node (int arrivalData)//Yapıcı Metod
    {
        data=arrivalData;
        
    }
    public void linkListPrint()
    {
        System.out.print(data+" ");
    }
}
class LList{
    private Node head,last;
    public LList(){
        head=null;//başlangıç değerlerini standart olarak null yaptık
        last=null;
    }
    public void addLeft(int arrData)
    {
        Node fresh=new Node(arrData);//yapıcı metodla yeni değeri alıp bir nesneye atadık
        fresh.next=head;////başada yeni değerin sonrasını koyduk
        head=fresh;//yeni değeri başa atadık
    }
    public void addRight(int arrData)
    {
        Node fresh =new Node(arrData);
        fresh.next=null;
        if (head==null) {
            head=fresh;
            last=fresh;
            fresh.next=null;
        }
        else{
            last.next=fresh;
            last=fresh;
            
        }
    }
    public void lListPrint()
    {
        Node active=head;
        while(active!=null)
        {
            active.linkListPrint();
            active=active.next;
        }
        System.out.println();
    }
    public void elementFind(int key)
    {
        Node active =head;
        while(active.data!=key){
            if (active.next==null) {
                return ;
            }
            else{
                active=active.next;
            }
        }
      
        System.out.print("İndis : "+active.data);
    }
    public Node elementDelete(int key)
    {
        Node active =head,pre=head;
        while(active.data!=key)
        {
            if (active.next==null) {
                return null;
            }
            else{
                pre=active;
                active=active.next;
            }
        }
        if (active==head) {
            head=head.next;
        }
        else{
            pre.next=active.next;
            
        }
        return active;
    }
    

    
}
public class BagliListeIslemleri {
    
    public static void main(String[] args) {
        LList l =new LList();   
        l.addRight(1);l.addRight(2);l.lListPrint();
        l.addLeft(3);l.lListPrint();
        l.addRight(4);
        l.lListPrint();
        l.elementFind(0);
        l.elementDelete(3);
        l.lListPrint();
        l.lListPrint();
    }
    
}
