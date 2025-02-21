program N155; //начало программы

const n = 10; //обозначение константы n
type massive=array[1..n] of real; //введение собственного типа massive

var
a:massive; //обозачаем массив своим типом
i:integer; //i-позиция в массиве
z:real; //z-сумматор
Logic: boolean; //выключатель кода
Question: Char; //Ответ на "выключатель" 
Way: string; //way - путь файла для записи
YourFile: text; //YourFile - вывод в файл

begin
  Logic:=false; //выключатель в режим "включен"
  writeln('Напиши адрес для создания отчета:');
  Readln(way); //считывание адреса для записи файла
  Assign(YourFile, Way); //объявление пути файла
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //проверка на файл
  while logic = false do begin //если выключатель "включен"

  writeln('Введите 10 чисел (по константе): ');
  readln(a[1]); //вводим первое число
  z:=1; //сумматору присваиваем значение 1 - чтобы не получилось 0 на выходе - далее идет операция умножения
  for i:=2 to n do begin
    readln(a[i]); //вводим второе число
    z:=z*((1/abs(a[i-1]+1))+a[i]); //расчитываем по формуле из задания
  end;
  writeln(YourFile,'Ответ: ',z); //выписываем ответ
  Writeln('Хотите использовать программу еще раз? Y\N');
  Readln(Question); //считывает ответ при Y-выключатель включен, при N-выключатель выключен
  If question = 'N' then Logic:= True; //если выключатель выключен
  end;
  closefile(YourFile); //закрываем файл
end. //конец программы

