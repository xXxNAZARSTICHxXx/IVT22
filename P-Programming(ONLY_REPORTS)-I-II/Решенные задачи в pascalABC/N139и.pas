program N139i; //начало программы

const h = 400; //обозначение константы n
type massive=array[1..h] of real; //введение собственного типа massive

var
a:massive; //обозачаем массив своим типом
i, n:integer; //i-позиция в массиве;j-факториал;n-конец позиции в массиве
x, t, j, s:real;  //x-сумматор
Logic: boolean; //выключатель кода
Question: Char; //Ответ на "выключатель" 
Way: string; //way - путь файла для записи
YourFile: text; //YourFile - вывод в файл

begin
  writeln('Напиши адрес для создания отчета:');
  Readln(way); //считывание адреса для записи файла
  Assign(YourFile, Way); //объявление пути файла
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //проверка на файл
  while logic = false do begin
  writeln('Введите длину n: ');
  readln(n);
  j:=1; //присвоение начального множителя факториала = 1
  t:=0;
  for i:=1 to n do begin
    j:=j*(1/(i)); //вычисление факториала через цикл,а не через fact
    a[i]:=i*((t)+(j)); //вычисление значения по задачи
    s:=i*((t)+(j)); 
    t:=t+j;
    end;
    writeln(YourFile,a[i]:0:4,' '); //вывод отчета
    Writeln('Хотите использовать программу еще раз? Y\N');
    Readln(Question); //считывает ответ при Y-выключатель включен, при N-выключатель выключен
    If question = 'N' then Logic:= True; //если выключатель выключен
    end;
  closefile(YourFile); //закрываем файл
end. //конец программы