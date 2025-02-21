using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using Newtonsoft.Json;
using System.Windows;
using System.Windows.Controls;
using System.Net.Http;
using System.Xml;
using HtmlAgilityPack;
using System.Windows.Media.Imaging;
using System.Windows.Documents;
using System.Windows.Media;
using Newtonsoft.Json.Linq;
using System.Security.Policy;
using System.Windows.Media.Media3D;
using System.Net.Sockets;
using System.Windows.Markup;
using ChatBot;
using System.Diagnostics;




/// <summary>
/// REGResponse - ����� �� ���������� ���������
/// </summary>
public class REGResponse
{

    /// <summary>
    /// REGHello - ���������� ��������� ����������� "���������������" ���������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGHello(string input)
    {
        string REG = "(������|���������|�����)"; // ���������� ��������� "������"
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) // �������� �� ���������� ���������
        {
            Random random = new Random(); // ��������� ���������� �����
            int randomNumber = random.Next(1, 5); // ��������� ���������� ������
            string[] responses = { "������", "����������", "������������", "�����������" }; // ������ ��������� �������
            string randomResponse = randomNumber > 0 && randomNumber <= responses.Length ? responses[randomNumber - 1] : ""; // ����� ���������� ������ �� �������
            return randomResponse; // ���������� ��������� �����
        }
        else return ""; // ���������� ������ ������
    }

    /// <summary>
    /// REGHowAreYou - ���������� ��������� ����������� "��� ��������" ���������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGHowAreYou(string input)
    {
        string REG = @"(��� � ���� ����|��� ����|��� ����������|��� �������)"; //���������� ��������� "��� ����"
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //�������� �� ����������� ���������, ���� ��� ����
        {
            Random random = new Random(); //��������� ���������� �����
            int randomNumber = random.Next(1, 7);
            string[] responses = { "� ���� ��� ������", "��� �����", "� ���� ��� �������", "� ���� ��� ��", "��� ���������", "�� ����� :}" }; // ������ ��������� �������
            string randomResponse = randomNumber > 0 && randomNumber <= responses.Length ? responses[randomNumber - 1] : ""; // ����� ���������� ������ �� �������
            return randomResponse; // ���������� ��������� �����
        }
        else return ""; // ���������� ������ ������
    }
    //todo case ��� ������
    /// <summary>
    /// REGLewd - ���������� ��������� ����������� �������� ���������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGLewd(string input)
    {
        string REG = @"((^|(\b))���)|(���|����|����|����|����|�����|�����|���|����|���|����|����|���|�����|�����|���|����|����|�����|���)"; //���������� ��������� �������� ����
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase))
        {   //todo case ��� ������
            Random random = new Random(); //��������� ���������� �����
            int randomNumber = random.Next(1, 6); //��������� ���������� ������
            string[] responses = { "����� ��� �����?", "�� ��������, �����", "�� ��������", "����� ��� �����", "��, ��� ����������" }; // ������ ��������� �������
            string randomResponse = randomNumber > 0 && randomNumber <= responses.Length ? responses[randomNumber - 1] : ""; // ����� ���������� ������ �� �������
            return randomResponse; // ���������� ��������� �����
        }
        else return "";  //������� ������ ������
    }

    /// <summary>
    /// REGGoodbye - ���������� ��������� ����������� "��������" ���������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGGoodbye(string input)
    {
        string REG = @"(����|�� ��������|�� ������ �������|������|���|���-���)";  //���������� ��������� "����"
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //�������� �� ����������� ���������, ���� ��� ����
        {
            Random random = new Random(); //��������� ���������� �����
            int randomNumber = random.Next(1, 5); //��������� ���������� ������
            string[] responses = { "�� ��������", "����", "�� ������ �������", "���-���" }; // ������ ��������� �������
            string randomResponse = randomNumber > 0 && randomNumber <= responses.Length ? responses[randomNumber - 1] : ""; // ����� ���������� ������ �� �������
            return randomResponse; // ���������� ��������� �����
        }
        return "";  //������� ������ ������
    }

    /// <summary>
    /// REGImage - ���������� ��������� ����������� "�����������" ���������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGImage(string input)
    {
        string REG = @"(����|��������)"; //���������� ��������� ��������
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //�������� �� ����������� ���������, ���� ��� ����
        {
            return " "; //�� ������� ������ - �� ������ ������
        }
        return ""; //����� ������� ������ ������
    }

    /// <summary>
    /// REGMultiply - ���������� ��������� ����������� ���������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGMultiply(string input)
    {
        string REG = @"(\d+)\s*\*\s*(\d+)"; //���������� ��������� ��� ������ �������� ���������

        Match match = Regex.Match(input, REG, RegexOptions.IgnoreCase); //������� ����� �������������� �� ��������
        if (match.Success) //���� ������� ����������
        {
            double num1 = double.Parse(match.Groups[1].Value); //��������� ����� �� ��������������� �����
            double num2 = double.Parse(match.Groups[2].Value); //��������� ����� �� ��������������� �����            
            double result = num1 * num2; //��������� �������� ���������
            return $"{num1} * {num2} = {result}"; //���������� ���������
        }
        else
        {
            return ""; //����� ������� ������ ������
        }
    }

    /// <summary>
    /// REGPlus - ���������� ��������� ����������� ��������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGPlus(string input)
    {
        string REG = @"(\d+)\s*\+\s*(\d+)"; //���������� ��������� ��� ������ �������� ��������
        Match match = Regex.Match(input, REG, RegexOptions.IgnoreCase); //������� ����� �������������� �� ��������
        if (match.Success) //���� ������� ����������
        {
            int num1 = int.Parse(match.Groups[1].Value); //��������� ����� �� ��������������� �����
            int num2 = int.Parse(match.Groups[2].Value); //��������� ����� �� ��������������� �����
            int result = num1 + num2; //��������� �������� ���������
            return $"{num1} + {num2} = {result}"; //���������� ���������
        }
        else
        {
            return ""; //����� ������� ������ ������
        }
    }

    /// <summary>
    /// REGMinus - ���������� ��������� ����������� �����
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGMinus(string input)
    {
        string REG = @"(\d+)\s*-\s*(\d+)"; //���������� ��������� ��� ������ �������� ���������
        Match match = Regex.Match(input, REG, RegexOptions.IgnoreCase); //������� ����� �������������� �� ��������
        if (match.Success) //���� ������� ����������
        {
            int num1 = int.Parse(match.Groups[1].Value); //��������� ����� �� ��������������� �����
            int num2 = int.Parse(match.Groups[2].Value); //��������� ����� �� ��������������� �����             
            int result = num1 - num2; //��������� �������� ���������
            return $"{num1} - {num2} = {result}"; //���������� ���������
        }
        else
        {
            return ""; //����� ������� ������ ������
        }
    }

    /// <summary>
    /// REGDivision - ���������� ��������� ����������� �������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGDivision(string input)
    {
        string REG = @"(\d+)\s*/\s*(\d+)"; //���������� ��������� ��� ������ �������� �������
        Match match = Regex.Match(input, REG, RegexOptions.IgnoreCase); //������� ����� �������������� �� ��������
        if (match.Success) //���� ������� ����������
        {
            int num1 = int.Parse(match.Groups[1].Value); //��������� ����� �� ��������������� �����
            int num2 = int.Parse(match.Groups[2].Value); //��������� ����� �� ��������������� �����
            double result = num1 / num2; //��������� �������� ���������
            return $"{num1} / {num2} = {result}"; //���������� ���������
        }
        else
        {
            return ""; //����� ������� ������ ������
        }
    }

    /// <summary>
    /// REGTime - ���������� ��������� ����������� "���������" ���������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGTime(string input)
    {
        string REG = @"(������� ���|������� �����|����� �����|�����)"; //���������� ��������� ��� ������ �������
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //�������� �� ����������� ���������, ���� ��� ����
        {
            DateTime currentTime = DateTime.Now; //�������� ������� �����
            string formattedTime = currentTime.ToString("HH:mm:ss"); //����������� ����� � ������ � ������� �������
            return formattedTime; //���������� ��������������� �����
        }
        return ""; //����� ������� ������ ������
    }

    /// <summary>
    /// REGData - ���������� ��������� ����������� "������" ���������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGData(string input)
    {
        string REG = @"(����� ������� �����|����|����������� ����)"; //���������� ��������� ��� ������ ����
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //�������� �� ����������� ���������, ���� ��� ����
        {
            DateTime currentDate = DateTime.Today; //�������� ����������� ����  
            string formattedDate = currentDate.ToString("dd.MM.yyyy"); //����������� ���� � ������ � ������� �������
            return formattedDate; //���������� ��������������� ����
        }
        return ""; //����� ������� ������ ������
    }

    /// <summary>
    /// REGTemperature - ���������� ��������� ����������� "�������������" ��������� � ��������� �����������
    /// </summary>
    /// <param name="input"> input - ���� ��������� </param>
    /// <returns></returns>
    public string REGTemperature(string input)
    {
        string REG = @"(����������� � ����|����������� �������|�����������|x)"; //���������� ��������� ��� ������ ����������� ������� � ������ ����
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //�������� �� ����������� ���������, ���� ��� ����
        {
            string answ = REGDynamicModule.GetCurrentTemperature(); //������� ����������� � ������
            if (answ.Contains("&minus;")) //���� ��� �������� "&minus;"
            {
                answ = answ.Replace("&minus;", "-"); //�������� �� �����
                return ("� ����: " + answ); //������� ��������� ����������� �������
            }
            return ("� ����: " + REGDynamicModule.GetCurrentTemperature()); //������� ��������� ����������� �������
        }
        return ""; //����� ������� ������ ������
    }

    public string REGCalc(string input)
    {
        string REG = @"(�����������|����)"; //���������� ��������� ��� ������ ����������� ������� � ������ ����
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //�������� �� ����������� ���������, ���� ��� ����
        {
            return ("��������..."); //������� ��������� ����������� �������
        }
        return ""; //����� ������� ������ ������
    }

}