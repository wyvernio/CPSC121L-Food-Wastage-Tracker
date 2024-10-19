#ifndef FOOD_WASTAGE_TRACKER_H_
#define FOOD_WASTAGE_TRACKER_H_

// Please fill in below.
// <Sean DeFrank>
// <CPSC 121L-13> (e.g. CPSC 121L-01)
// <12-03-2023>
// <wyvernio@csu.fullerton.edu>
// <wyvernio>

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "food_wastage_record.h"
#include "food_wastage_report.h"
class FoodWastageTracker {
  
 public:
  FoodWastageTracker() {}

  bool AddRecord(const FoodWastageRecord& new_record);
  const std::vector<FoodWastageRecord> GetRecords() const { return records_; }
  bool DeleteRecord(const FoodWastageRecord& record);
  FoodWastageReport GetFoodWastageReport() const;
  FoodWastageReport GenerateReport() const;

 private:
  std::vector<FoodWastageRecord> records_;
};

#endif
