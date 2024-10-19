// Please fill in below.
// <Sean DeFrank>
// <CPSC 121L-13> (e.g. CPSC 121L-01)
// <12-03-2023>
// <wyvernio@csu.fullerton.edu>
// <wyvernio>

#include "food_wastage_tracker.h"

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (food_wastage_tracker.h), only
// if you didn't implement them inline within food_wastage_tracker.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the FoodWastageTracker
// class.
// ===================================================================
bool FoodWastageTracker::AddRecord(const FoodWastageRecord& new_record) {
  for (const FoodWastageRecord& record : records_) {
    if (record.GetCost() == new_record.GetCost() &&
        record.GetDate() == new_record.GetDate() &&
        record.GetDisposalMechanism() == new_record.GetDisposalMechanism() &&
        record.GetMeal() == new_record.GetMeal() &&
        record.GetQuantityInOz() == new_record.GetQuantityInOz() &&
        record.GetWastageReason() == new_record.GetWastageReason() &&
        record.GetFoodName() == new_record.GetFoodName()) {
      return false;
    }
  }
  records_.push_back(new_record);
  return true;
}

bool FoodWastageTracker::DeleteRecord(const FoodWastageRecord& record) {
  for (const auto& recordit : records_) {
    if (recordit.GetCost() == record.GetCost() &&
        recordit.GetDate() == record.GetDate() &&
        recordit.GetDisposalMechanism() == record.GetDisposalMechanism() &&
        recordit.GetMeal() == record.GetMeal() &&
        recordit.GetQuantityInOz() == record.GetQuantityInOz() &&
        recordit.GetWastageReason() == record.GetWastageReason() &&
        recordit.GetFoodName() == record.GetFoodName()) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

FoodWastageReport FoodWastageTracker::GenerateReport() const {
  return FoodWastageReport(records_);
}

FoodWastageReport FoodWastageTracker::GetFoodWastageReport() const {
  return GenerateReport();
}
