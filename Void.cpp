export module Ph.Concepts.Void;

import Ph.Concepts.Same_as;

export template <typename T>
concept Void = Same_as <T, void>;
