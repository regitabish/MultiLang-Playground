def firstTwo(list:List[String]):List[String]={
    list.slice(0,2);
}

def lastTwo(list:List[String]):List[String]={
    list.slice(list.size-2,list.size)
}

def movedFirstTwoTheEnd(list:List[String]):List[String]={
    val firstTwo = list.slice(0,2)
    val withoutFirstTwo = list.slice(2,list.size)
    withoutFirstTwo.appendedAll(firstTwo)
}

def insertedBeforeLast(list:List[String], element:String):List[String]={
    val withoutLast = list.slice(0,list.size-1)
    val last = list.slice(list.size-1,list.size)
    withoutLast.appended(element).appendedAll(last)
}