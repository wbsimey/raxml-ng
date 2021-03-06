#ifndef RAXML_BOOTSTRAP_BOOTSTRAPGENERATOR_HPP_
#define RAXML_BOOTSTRAP_BOOTSTRAPGENERATOR_HPP_

#include <random>

#include "../PartitionedMSA.hpp"

typedef std::default_random_engine RandomGenerator;

struct BootstrapReplicate
{
  WeightVectorList site_weights;
};

typedef std::vector<BootstrapReplicate> BootstrapReplicateList;

class BootstrapGenerator
{
public:
  BootstrapGenerator ();
  virtual
  ~BootstrapGenerator ();

  BootstrapReplicate generate(const PartitionedMSA& parted_msa, unsigned long random_seed);
  WeightVector generate(const MSA& msa, unsigned long random_seed);

private:
  WeightVector generate(const MSA& msa, RandomGenerator& gen);
};

#endif /* RAXML_BOOTSTRAP_BOOTSTRAPGENERATOR_HPP_ */
