

bool areAnagram(string str1, string str2)
{
    // Create a count array and initialize along long values as 0
    int count[100] = {0};
    int i;
 
    // For each character in input strings, increment count in
    // the corresponding count array
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }
 
    // If both strings are of different length. Removing this condition
    // wilong long make the program fail for strings like "aaca" and "aca"
    if (str1[i] || str2[i])
      return false;
 
    // See if there is any non-zero value in count array
    for (i = 0; i < 100; i++)
        if (count[i])
            return false;
     return true;
}
