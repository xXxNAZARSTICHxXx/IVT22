using System.Collections.Generic;
using System.Linq;
using System;
using Xamarin.Forms;
using SkiaSharp;

///Пространство SudokuEXE 
namespace SudokuEXE
{
    /// <summary>
    /// ContentXElements - это класс всех полей и всех объектов присутствующих на форме
    /// </summary>
    public class ContentXElements
    {
        /// <summary>
        /// AbsoluteLayout - форма
        /// </summary>
        public Xamarin.Forms.AbsoluteLayout AbsoluteLayout { get; set; }
        /// <summary>
        /// Frame1 - рамка с текстом SudokU над игровым полем
        /// </summary>
        public Frame Frame1 { get; set; }
        /// <summary>
        /// Frame2 - надпись You WIN!
        /// </summary>
        public Frame Frame2 { get; set; }
        /// <summary>
        /// CanvasView - поле, где рисуется поле Судоку
        /// </summary>
        public SkiaSharp.Views.Forms.SKCanvasView CanvasView { get; set; }
        /// <summary>
        /// KeyboardGrid - Сетка с клавиатурой(кнопками)
        /// </summary>
        public Grid KeyboardGrid { get; set; }
        /// <summary>
        /// EditableGrid - Сетка с 81 полем 
        /// </summary>
        public Grid EditableGrid { get; set; }
        /// <summary>
        /// Label1 - текст SudokU над игровым полем
        /// </summary>
        public Label Label1 { get; set; }
        /// <summary>
        /// Label2 - текст надписи You WIN!
        /// </summary>
        public Label Label2 { get; set; }
        /// <summary>
        /// DataGrid - сам Grid с полями
        /// </summary>
        public Grid DataGrid { get; set; }
        /// <summary>
        /// Entries - набор из 81 поля
        /// </summary>
        public Entry[,] Entries { get; set; }
    }

    /// <summary>
    /// Класс генератора судоку (логика)
    /// </summary>
    public class SudokuGenerator
    {
        /// <summary>
        /// Генератор рандома
        /// </summary>
        private Random random;

        public SudokuGenerator()
        {
            random = new Random();
        }

        /// <summary>
        /// Генератор случайного судоку
        /// </summary>
        /// <returns></returns>
        public int[,] Generate()
        {
            int[,] sudoku = new int[9, 9];

            FillSudoku(sudoku);
            SwapRowsAndColumns(sudoku);

            return sudoku;
        }

        /// <summary>
        /// Заполнение судоку
        /// </summary>
        /// <param name="sudoku"></param>
        private void FillSudoku(int[,] sudoku)
        {
            List<int> numbers = new List<int>(Enumerable.Range(1, 9));
            Shuffle(numbers);

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    sudoku[i, j] = numbers[(i * 3 + i / 3 + j) % 9];
                }
            }
        }

        /// <summary>
        /// Замена столбцов
        /// </summary>
        /// <param name="sudoku"></param>
        private void SwapRowsAndColumns(int[,] sudoku)
        {
            for (int i = 0; i < 9; i += 3)
            {
                for (int j = 0; j < 9; j++)
                {
                    int row1 = random.Next(i, i + 3);
                    int row2 = random.Next(i, i + 3);
                    SwapRows(sudoku, row1, row2);
                }
            }

            for (int i = 0; i < 9; i += 3)
            {
                for (int j = 0; j < 9; j++)
                {
                    int col1 = random.Next(i, i + 3);
                    int col2 = random.Next(i, i + 3);
                    SwapColumns(sudoku, col1, col2);
                }
            }
        }

        /// <summary>
        /// Замена строк
        /// </summary>
        /// <param name="sudoku"></param>
        /// <param name="row1"></param>
        /// <param name="row2"></param>
        private void SwapRows(int[,] sudoku, int row1, int row2)
        {
            for (int i = 0; i < 9; i++)
            {
                int temp = sudoku[row1, i];
                sudoku[row1, i] = sudoku[row2, i];
                sudoku[row2, i] = temp;
            }
        }

        /// <summary>
        /// Замена столбцов
        /// </summary>
        /// <param name="sudoku"></param>
        /// <param name="col1"></param>
        /// <param name="col2"></param>
        private void SwapColumns(int[,] sudoku, int col1, int col2)
        {
            for (int i = 0; i < 9; i++)
            {
                int temp = sudoku[i, col1];
                sudoku[i, col1] = sudoku[i, col2];
                sudoku[i, col2] = temp;
            }
        }

        /// <summary>
        /// Метод перемешения
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="list"></param>
        private void Shuffle<T>(IList<T> list)
        {
            int n = list.Count;
            while (n > 1)
            {
                n--;
                int k = random.Next(n + 1);
                T value = list[k];
                list[k] = list[n];
                list[n] = value;
            }
        }
    }

}