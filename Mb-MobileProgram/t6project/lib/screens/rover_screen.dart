import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import '../cubit/rover_cubit.dart';
import '../cubit/rover_state.dart'; // Импорт состояний
import './detail_screen.dart';

class RoverScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return BlocProvider(
      create: (_) => RoverCubit()..loadData(),
      child: Scaffold(
        appBar: AppBar(
          title: const Text('Mars Rover Photos'), 
        ),
        body: BlocBuilder<RoverCubit, RoverState>(
          builder: (context, state) {
            // Состояние загрузки
            if (state is RoverLoadingState) {
              return const Center(
                child: CircularProgressIndicator(),
              );
            }
            // Состояние успешной загрузки
            else if (state is RoverLoadedState) {
              return ListView.builder(
                itemCount: state.photos.length,
                itemBuilder: (context, index) {
                  final photo = state.photos[index];
                  return ListTile(
                    leading: Image.network(
                      photo.imgSrc,
                      width: 50,
                      height: 50,
                      fit: BoxFit.cover,
                    ),
                    title: Text(photo.rover.name),
                    subtitle: Text('Sol: ${photo.rover.status}'),
                    onTap: () {
                      // Переход на экран с деталями фотографии
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (context) => DetailScreen(photo: photo),
                        ),
                      );
                    },
                  );
                },
              );
            }
            // Состояние ошибки
            else if (state is RoverErrorState) {
              return Center(
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    const Text('Error loading data'), 
                    const SizedBox(height: 16), 
                    ElevatedButton(
                      onPressed: () {
                        // Повторная попытка загрузки данных
                        context.read<RoverCubit>().loadData();
                      },
                      child: const Text('Retry'), 
                    ),
                  ],
                ),
              );
            }
            // Состояние по умолчанию
            return Container();
          },
        ),
      ),
    );
  }
}