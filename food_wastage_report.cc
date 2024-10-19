#include "food_wastage_report.h"

#include <algorithm>
#include <iterator>
#include <memory>
#include <unordered_map>

#include "food_wastage_record.h"


FoodWastageReport::FoodWastageReport(
    const std::vector<FoodWastageRecord>& food_waste_records)
    : food_waste_records_(food_waste_records) {}

std::vector<std::string> FoodWastageReport::MostCommonlyWastedFoods() const {
  std::unordered_map<std::string, int> food_count;
  for (FoodWastageRecord x : food_waste_records_) {
    food_count[x.GetFoodName()]++;
  }
  std::vector<std::string> most_common_foods;
  int max_count = 0;
  for (const auto& entry : food_count) {
    if (entry.second > max_count) {
      most_common_foods.clear();
      most_common_foods.push_back(entry.first);
      max_count = entry.second;
    } else if (entry.second == max_count) {
      most_common_foods.push_back(entry.first);
    }
  }
  return most_common_foods;
}

std::vector<std::string> FoodWastageReport::MostCostlyWasteProducingMeals()
    const {
  const std::vector<FoodWastageRecord>& records = food_waste_records_;
  std::vector<FoodWastageRecord> sortedRecords = records;
  std::sort(sortedRecords.begin(), sortedRecords.end(),
            [](const FoodWastageRecord& a, const FoodWastageRecord& b) {
              return a.GetCost() > b.GetCost();
            });

  std::vector<std::string> most_costly_meal;
  double maxCost = 0.0;
  for (const auto& record : sortedRecords) {
    if (record.GetCost() > maxCost) {
      most_costly_meal.clear();
      most_costly_meal.push_back(record.GetMeal());
      maxCost = record.GetCost();
    } else if (record.GetCost() == maxCost) {
      most_costly_meal.push_back(record.GetMeal());
    }
  }

  return most_costly_meal;
}

double FoodWastageReport::TotalCostOfFoodWasted() const {
  const std::vector<FoodWastageRecord>& records = food_waste_records_;
  double total_cost = 0.0;
  for (const auto& record : records) {
    total_cost += record.GetCost();
  }
  return total_cost;
}

std::vector<std::string> FoodWastageReport::MostCommonWastageReason() const {
  const std::vector<FoodWastageRecord>& records = food_waste_records_;
  std::unordered_map<std::string, int> wastage_reason_count;

  // Count occurrences of each wastage reason
  for (const auto& record : records) {
    wastage_reason_count[record.GetWastageReason()]++;
  }

  std::vector<std::string> most_common_reasons;
  int max_count = 0;

  // Find the maximum occurrence count
  for (const auto& entry : wastage_reason_count) {
    if (entry.second > max_count) {
      most_common_reasons.clear();
      most_common_reasons.push_back(entry.first);
      max_count = entry.second;
    } else if (entry.second == max_count) {
      most_common_reasons.push_back(entry.first);
    }
  }

  return most_common_reasons;
}

std::vector<std::string> FoodWastageReport::MostCommonDisposalMechanisms()
    const {
  const std::vector<FoodWastageRecord>& records = food_waste_records_;
  std::unordered_map<std::string, int> dispoalMechanismCount;
  for (const auto& record : records) {
    dispoalMechanismCount[record.GetDisposalMechanism()]++;
  }

  std::vector<std::string> most_common_mechanisms;
  int max_count = 0;
  for (const auto& entry : dispoalMechanismCount) {
    if (entry.second > max_count) {
      most_common_mechanisms.clear();
      most_common_mechanisms.push_back(entry.first);
      max_count = entry.second;
    } else if (entry.second == max_count) {
      most_common_mechanisms.push_back(entry.first);
    }
  }

  return most_common_mechanisms;
}

std::vector<std::string> FoodWastageReport::SuggestWasteReductionStrategies()
    const {
  std::vector<std::string> common_reasons = MostCommonWastageReason();
  std::vector<std::string> suggested_strategies;
  if (!common_reasons.empty()) {
    bool donate = false;
    bool less_food = false;
    bool cook_small_serv = false;
    bool recycle = true;
    for (std::string common_reason : common_reasons) {
      if (common_reason == "Expired") {
        donate = true;
        recycle = false;
      } else if (common_reason == "Tastes bad") {
        less_food = true;
      } else if (common_reason == "Too much left overs") {
        less_food = true;
        cook_small_serv = true;
      }
    }
    if (donate) {
      suggested_strategies.push_back("Donate before expiration");
    }
    if (less_food) {
      suggested_strategies.push_back("Buy less food");
    }
    if (cook_small_serv) {
      suggested_strategies.push_back("Cook small servings");
    }
    if (recycle) {
      suggested_strategies.push_back("Recycle left overs");
    }
  }
  return suggested_strategies;
}
