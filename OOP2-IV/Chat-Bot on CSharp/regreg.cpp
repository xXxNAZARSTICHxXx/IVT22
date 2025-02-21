public static string REGHello(string input)
{
    string REG = @"(привет|здравству|здрас)";
    if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase))
    {
        Random random = new Random();
        int randomNumber = random.Next(1, 5);
        if (randomNumber == 1) { return "Привет"; }
        if (randomNumber == 2) { return "Здравствуй"; }
        if (randomNumber == 3) { return "Здравствуйте"; }
        if (randomNumber == 4) { return "Приветствую"; }
    }
    return "";
}

public static string REGHowAreYou(string input)
{
    string REG = @"(Как у тебя дела|Как дела|Как настроение|Как делишки)";
    if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase))
    {
        Random random = new Random();
        int randomNumber = random.Next(1, 7);
        if (randomNumber == 1) { return "У меня все хорошо"; }
        if (randomNumber == 2) { return "Все путем"; }
        if (randomNumber == 3) { return "У меня все классно"; }
        if (randomNumber == 4) { return "У меня все хорошо, я надеюсь у тебя тоже все хорошо"; }
        if (randomNumber == 5) { return "Все нормально"; }
        if (randomNumber == 6) { return "Не скажу :}"; }
    }
    return "";
}

public static string REGLewd(string input)
{
    string REG = @"((^|(\b))бля)|(хуй|пизд|ебан|ебат|пидр|пидор|залуп|ебёш|ёбан|ебёт|ёпта|ебет|еби|мудил|мудак|еба|охуе|ахуе|минет|хуя)";
    if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase))
    {   //todo case или массив
        Random random = new Random();
        int randomNumber = random.Next(1, 6);
        if (randomNumber == 1) { return "Можно пожалуйста без этих выражений?"; }
        if (randomNumber == 2) { return "Не матерись, блять"; }
        if (randomNumber == 3) { return "Не матерись"; }
        if (randomNumber == 4) { return "Можно без матов"; }
        if (randomNumber == 5) { return "Фу, как нкультурно"; }
    }
    return "";
}

public static string REGGoodbye(string input)
{
    string REG = @"(Пока|До свидания|До скорой встречи|Покеда|Чао|Бай-бай)";
    if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase))
    {
        Random random = new Random();
        int randomNumber = random.Next(1, 6);
        if (randomNumber == 1) { return "До свидания"; }
        if (randomNumber == 2) { return "Пока"; }
        if (randomNumber == 3) { return "До скорой встречи"; }
        if (randomNumber == 4) { return "Бай-бай"; }
    }
    return "";
}