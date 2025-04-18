import 'package:flutter_bloc/flutter_bloc.dart';
import '../services/api_service.dart';
import 'rover_state.dart';

class RoverCubit extends Cubit<RoverState> {
  RoverCubit() : super(RoverLoadingState());

  void loadData() async {
    emit(RoverLoadingState());
    try {
      final photos = await fetchRoverPhotos();
      emit(RoverLoadedState(photos));
    } catch (e) {
      emit(RoverErrorState());
    }
  }
}