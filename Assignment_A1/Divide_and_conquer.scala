import scala.annotation.tailrec
object BinarySearcher {
    def search(target:Int, l:List[Int]) = { // binary search function
        @tailrec
        def recursion(low:Int, high:Int):Integer = (low+high)/2 match {
            case _ if high < low => -1;
            case mid if l(mid) > target => recursion(low, mid-1);
            case mid if l(mid) < target => recursion(mid+1, high);
            case mid => mid;
        }
        recursion(0,l.size - 1);
    }
}

val l = List(1,2,4,5,6,8,9,25,31);
print("Current List: "); println(l);
print("Search Element 5: "); println(BinarySearcher.search(5, l));
print("Search Element 6: "); println(BinarySearcher.search(6, l));
print("Search Element 99: "); println(BinarySearcher.search(99, l));
