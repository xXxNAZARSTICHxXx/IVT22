program N427;
var
a,b,c:real; //a,b,c фактические переменные для вычислений;
Logic: boolean; //выключатель кода
Question: Char; //Ответ на "выключатель" 
Way: string; //way - путь файла для записи
YourFile: text; //YourFile - вывод в файл
procedure input(var a:real; var b:real; var c:real); //ввод чисел
begin
  write('Введите число А: ');
  readln(a);
  write('Введите число B: ');
  readln(b);
  write('Введите число C: ');
  readln(c);
end;

function answer(a,b,c:real):real; //из условия задачи - первый max
begin
  answer:=(max(a,a+b)+ max(a,b+c))/(1+max(a+b*c,1.15));
end;

begin
  Logic:=false;
  writeln('Напиши адрес для создания отчета:');
  Read(way); //считывание адреса для записи файла
  Assign(YourFile, Way); //объявление пути файла
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //проверка на файл
  while logic = false do begin
    input(a,b,c); //ввод значение
    writeln('Ответ: ',answer(a,b,c)); //вывод результата
    writeln(YourFile,'Ответ: ',answer(a,b,c)); //вывод результата в файл
    writeln(YourFile);
    Writeln('Хотите использовать программу еще раз? Y\N'); 
    Read(Question); //считывает ответ при Y-выключатель включен, при N-выключатель выключен
    if question = 'N' then Logic:= True; //если выключатель выключен
  end;
  closefile(YourFile); //закрываем файл
end.
