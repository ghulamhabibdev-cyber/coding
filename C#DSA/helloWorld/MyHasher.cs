using System;
using System.Text;
using System.Security.Cryptography;
using System.Runtime.Intrinsics.Arm;
public class MyHasher
{
    public static void RunCoder()
    {
        System.Console.WriteLine("Hello Runner");
    }
    public string HashString(string str)
    {
        using (var sha256 = SHA256.Create())
        {
            var bytes = Encoding.UTF8.GetBytes(str);
            var currHash = sha256.ComputeHash(bytes);
            var strHash = Convert.ToBase64String(currHash);
            System.Console.WriteLine("My hash : " + currHash);
            System.Console.WriteLine("My Bytes : " + bytes);
            return strHash;
        }
    }
    public bool VerifyHash(string str,string hashStr)
    {
        var currHash=HashString(str);
        return currHash==hashStr;
    }


}