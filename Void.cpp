export module Ph.Concepts.Void;

import Ph.Concepts.Same_as;

namespace ph 
{

export template <typename T>
concept Void = Same_as <T, void>;


}