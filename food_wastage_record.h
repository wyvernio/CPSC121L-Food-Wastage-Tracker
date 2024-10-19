#ifndef FOOD_WASTAGE_RECORD_H_
#define FOOD_WASTAGE_RECORD_H_

// <Sean DeFrank>
// <CPSC 121L-13> (e.g. CPSC 121L-01)
// <12-03-2023>
// <wyvernio@csu.fullerton.edu>
// <wyvernio>
#include <iostream>
#include <string>

class FoodWastageRecord {



 public:
  FoodWastageRecord() {}
  FoodWastageRecord(const std::string& date, const std::string& meal,
                    const std::string& food_name, double quantity_in_oz,
                    const std::string& wastage_reason,
                    const std::string& disposal_mechanism, double cost)
      : date_(date),
        meal_(meal),
        food_name_(food_name),
        qty_in_oz_(quantity_in_oz),
        wastage_reason_(wastage_reason),
        disposal_mechanisim_(disposal_mechanism),
        cost_(cost) {}

  void SetDate(const std::string& date) { date_ = date; }
  void SetMeal(const std::string& meal) { meal_ = meal; }
  void SetFoodName(const std::string& food_name) { food_name_ = food_name; }
  void SetQuantityInOz(double quantity_in_oz) { qty_in_oz_ = quantity_in_oz; }
  void SetWastageReason(const std::string& wastage_reason) {
    wastage_reason_ = wastage_reason;
  }
  void SetDisposalMechanism(const std::string& disposal_mechanism) {
    disposal_mechanisim_ = disposal_mechanism;
  }
  void SetCost(double cost) { cost_ = cost; }

  std::string GetDate() const { return date_; }
  std::string GetMeal() const { return meal_; }
  std::string GetFoodName() const { return food_name_; }
  double GetQuantityInOz() const { return qty_in_oz_; }
  std::string GetWastageReason() const { return wastage_reason_; }
  std::string GetDisposalMechanism() const { return disposal_mechanisim_; }
  double GetCost() const { return cost_; }

 private:
  std::string date_;
  std::string meal_;
  std::string food_name_;
  double qty_in_oz_;
  std::string wastage_reason_;
  std::string disposal_mechanisim_;
  double cost_;
};

#endif
