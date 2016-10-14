object Test{
  
  def main(args: Array[String])
  {
  	//Read the count of elements.
  	println("Enter the List Elements separated by spaces ");
  	//object.map(*) parses stuff to type *. Gotta look into what * could be.
	var list=readLine.split(" ").map(_.toInt)

  	//Sort the list using Quicksort.
  	scala.util.Sorting.quickSort(list)
	//Thank god for libraries.
  	println("\n\n");
  	for(a <- 0 to (count1-1))
 		println("Element: "+ (a+1) + " ---->  "+ list(a));
  	
 	println("\n\nEnter element to search : ");
	//Console for input interactions only???
  	var j = Console.readInt;
  	var i = binarySearchIterative(list, j);
  	var k = binarySearchRecursive(list, 0, (count1-1), j);
  	if(i== (-1) && k== (-1))
    		println("\nElement Not Found");
  	else
    		println("\nElement found at position "+ (i+1));
  }
//functions are defined as=> def fname(varname: vartype) : return type = {}
//functions without returns => def fname(varname: vartype) {}
def binarySearchIterative(list: Array[Int], target: Int) : Int = {
  var left = 0;
  var right = list.length-1;
  while(left <= right)
  {
    val mid = left + (right-left)/2;
    // If the element is present at the middle itself
    if(list(mid)==target)
      return mid;
      
    // If element is smaller than mid, then it can only be present in left subarray
    else if (list(mid)>target)
      right = mid - 1;
      
    // Else the element can only be present in right subarray
    else
      left = mid + 1;
  }
  
  // We reach here when element is not present in array
  -1
}

def binarySearchRecursive(list: Array[Int], l: Int, r: Int, target: Int) : Int ={
	
	if (r >= l)
   	{
        val mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (list(mid) == target)  
        	return mid;
 
        // If element is smaller than mid, then it can only be present in left subarray
        if (list(mid) > target) 
        	return binarySearchRecursive(list, l, mid-1, target);
 
        // Else the element can only be present in right subarray
        return binarySearchRecursive(list, mid+1, r, target);
    }
 
   // We reach here when element is not present in array
   -1;
}

}
