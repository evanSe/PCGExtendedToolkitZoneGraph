// Copyright 2026 Timothée Lapetite and contributors
// Released under the MIT license https://opensource.org/license/MIT/

#include "Graph/PCGExClusterToZoneGraph.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FPCGExClusterToZoneGraphReversedRoadRadiusAssignmentTest,
	"PCGEx.ZoneGraph.ClusterToZoneGraph.ReversedRoadRadiusAssignment",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPCGExClusterToZoneGraphReversedRoadRadiusAssignmentTest::RunTest(const FString& Parameters)
{
	using namespace PCGExClusterToZoneGraph;

	TestTrue(TEXT("Matching node identity maps to the materialized road start"), IsPrecomputedRoadStart(10, 10));
	TestFalse(TEXT("Opposite single-edge storage direction maps the seed junction to the road end"), IsPrecomputedRoadStart(10, 20));
	TestTrue(TEXT("Reversed materialization maps the other junction to the road start"), IsPrecomputedRoadStart(20, 20));
	TestFalse(TEXT("The other junction never claims the materialized start"), IsPrecomputedRoadStart(20, 10));

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FPCGExClusterToZoneGraphEndpointTrimDirectionTest,
	"PCGEx.ZoneGraph.ClusterToZoneGraph.EndpointTrimDirection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPCGExClusterToZoneGraphEndpointTrimDirectionTest::RunTest(const FString& Parameters)
{
	using namespace PCGExClusterToZoneGraph;

	TestEqual(TEXT("Materialized road start advances away from its junction"), GetPrecomputedEndpointTrimSign(true), 1.0);
	TestEqual(TEXT("Materialized road end retreats away from its junction"), GetPrecomputedEndpointTrimSign(false), -1.0);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FPCGExClusterToZoneGraphClosedLoopTerminalAppendTest,
	"PCGEx.ZoneGraph.ClusterToZoneGraph.ClosedLoopTerminalAppend",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPCGExClusterToZoneGraphClosedLoopTerminalAppendTest::RunTest(const FString& Parameters)
{
	using namespace PCGExClusterToZoneGraph;

	TArray<int32> Nodes;
	Nodes.Reserve(6);
	Nodes.Append({ 2, 4, 6, 8, 10, 12 });
	TestEqual(TEXT("Fixture fills its allocation before the append"), Nodes.Num(), Nodes.Max());

	AppendClosedLoopTerminal(Nodes);

	TestEqual(TEXT("Closed loop receives one terminal node"), Nodes.Num(), 7);
	TestEqual(TEXT("Terminal node repeats the previous last node"), Nodes.Last(), 12);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FPCGExClusterToZoneGraphJunctionDegreeGateTest,
	"PCGEx.ZoneGraph.ClusterToZoneGraph.JunctionDegreeGate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPCGExClusterToZoneGraphJunctionDegreeGateTest::RunTest(const FString& Parameters)
{
	using namespace PCGExClusterToZoneGraph;

	TestFalse(TEXT("An isolated node is not a junction"), IsJunctionDegree(0));
	TestFalse(TEXT("A leaf is not a junction"), IsJunctionDegree(1));
	TestFalse(TEXT("A binary closed-loop seam is not a junction"), IsJunctionDegree(2));
	TestTrue(TEXT("A three-way node is a junction"), IsJunctionDegree(3));
	TestTrue(TEXT("A four-way node is a junction"), IsJunctionDegree(4));

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FPCGExClusterToZoneGraphAnchoredLoopMaterializationTest,
	"PCGEx.ZoneGraph.ClusterToZoneGraph.AnchoredLoopMaterialization",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPCGExClusterToZoneGraphAnchoredLoopMaterializationTest::RunTest(const FString& Parameters)
{
	using namespace PCGExClusterToZoneGraph;

	TArray<int32> ForwardNodes = { 10, 11, 12 };
	MaterializeJunctionAnchoredLoop(ForwardNodes, 10);
	TestEqual(TEXT("Forward loop opens at the seed on both ends"), ForwardNodes, TArray<int32>({ 10, 11, 12, 10 }));

	TArray<int32> ReversedNodes = { 12, 11, 10 };
	MaterializeJunctionAnchoredLoop(ReversedNodes, 10);
	TestEqual(TEXT("Reversed loop opens at the seed on both ends"), ReversedNodes, TArray<int32>({ 10, 12, 11, 10 }));

	TestTrue(TEXT("Forward materialized start maps to the opening side"), GetChainExitSide(true, false));
	TestFalse(TEXT("Forward materialized end maps to the closing side"), GetChainExitSide(false, false));
	TestFalse(TEXT("Reversed materialized start maps to the closing side"), GetChainExitSide(true, true));
	TestTrue(TEXT("Reversed materialized end maps to the opening side"), GetChainExitSide(false, true));

	return true;
}

#endif
