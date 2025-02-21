program N114a; //название программы
var i : integer; j,k : real; // декларативная часть

Logic: boolean; // переменные для вывода в txt
Question: Char; // переменные для вывода в txt
Way: string; // переменные для вывода в txt
YourFile: text; // переменные для вывода в txt

begin // начало исполнительной части
  Logic:=false; //вся эта часть для создания отчета
  writeln('Напиши адрес для создания отчета:'); //
  Readln(way); //
  Assign(YourFile, Way); //
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //
  while logic = false do begin //

  k:=0; // задаем сумматор
  for i := 1 to 100 do begin // цикл
    j:=i*i; // возводим в степерь
    k:=k+(1/j); // выполняем выражение
    end; // конец цикла
  writeln(YourFile, 'Ответ: ',k); // вывод результата 
  
  Writeln('Хотите использовать программу еще раз? Y\N'); // бесконечный цикл на повторение кода
  Readln(Question); //
  If question = 'N' then Logic:= True; //
  end; //
  closefile(YourFile); // закрытите сохраненного файла
end. //конец програамы
