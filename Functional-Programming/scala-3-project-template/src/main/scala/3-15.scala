def abbreviate(stringParameter:String) :String = {
    val initial = stringParameter.substring(0,1)
    val separator = stringParameter.indexOf(' ')
    val lastName = stringParameter.substring(separator+1)

    initial + '.' + lastName
}